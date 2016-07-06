#include "Signaling.h"

const byte PIN=6;    //output PWM pin

Signaling::Signaling(uint16_t pixels, uint8_t pin, uint8_t type):Adafruit_NeoPixel(pixels, pin, type){

//OnComplete = callback;
}

// Update the pattern
void Signaling::Update(Update_Data *a)
{

        if((millis() - a->lastUpdate) > a->Interval) // time to update
        {

            switch(a->pattern)
            {
                case RAINBOW_CYCLE:
                    RainbowCycleUpdate(a);
                    break;
                case THEATER_CHASE:
                    TheaterChaseUpdate(a);
                    break;
                case COLOR_WIPE:
                    ColorWipeUpdate(a);
                    break;
                case SCANNER:
                    ScannerUpdate(a);
                    break;
                case FADE:
                    FadeUpdate(a);
                    break;
                case BLINK:
                    BlinkUpdate(a);
                    break;
                case ON_AND_OFF:
                    OnOffUpdate(a);
                    break;
                case PULSATING:
                    if( millis() < 100)
                    {
                        setPixelColor(10, Brightness(a->Color1, a->Color1, 20));
                        show();
                    }
                    PulsatingUpdate(a);
                    break;
                case LOADING:
                    LoadingUpdate(a);
                    break;
                case STEP:
                    StepUpdate(a);
                    break;
                default:
                    break;
            }
            a->lastUpdate = millis();
        }
    }

//change the status of the  pattern and make all the modules of that group blank
void Signaling::OnComplete(Update_Data *a)
{
    for( int i = 0; i < a->groupLength; i++)
    {
        setPixelColor(a->group[i], 0, 0, 0, 0);
    }
    show();
}
    // Increment the Index and reset at the end
void Signaling::Increment(Update_Data *p)
    {
        if (p->direction == FORWARD)
        {
           p->Index++;
           // p->totalsteps++;
          // if (p->Index >= p->totalsteps)
        //    {
         //       p->Index = 0;
           /*     if (p->totalsteps>=(p->groupLength*p->cycles))
                {
                    p->complete=OnComplete(p->complete); // call the comlpetion callback
                }*/
           // }
        }
        else // Direction == REVERSE
        {
            --p->Index;
            if (p->Index <= 0)
            {
                p->Index = p->groupLength-1;
             /*   if (p->totalsteps>=(p->groupLength*p->cycles))
                {
                    p->complete=OnComplete(p->complete); // call the comlpetion callback
                }*/
            }
        }
    }

// Update the Rainbow Cycle Pattern
void Signaling::RainbowCycleUpdate(Update_Data *b)
    {
        for(int i=0; i< (b->groupLength); i++)
        {
            setPixelColor(b->group[i], Wheel(((i * 256 / b->groupLength) + b->Index) & 255));
        }
        show();
        Increment(b);
    }

// Update the Theater Chase Pattern
void Signaling::TheaterChaseUpdate(Update_Data *b)
    {
        for(int i=0; i< b->groupLength; i++)
        {
            if ((i + b->Index) % 3 == 0)
            {
                setPixelColor(b->group[i], b->Color1);
            }
            else
            {
                setPixelColor(b->group[i], b->Color2);
            }
        }
        show();
        Increment(b);
}

// Update the Color Wipe Pattern
void Signaling::ColorWipeUpdate(Update_Data *b)
{
        setPixelColor(b->group[b->Index], b->Color1);
        show();
        Increment(b);
}

    // Update the Scanner Pattern
void Signaling::ScannerUpdate(Update_Data *b)
{
        for (int i = 0; i < b->groupLength; i++)
        {
            if (i == b->Index)  // Scan Pixel to the right
            {
                 setPixelColor(b->group[i], b->Color1);
            }
            else if (i == b->totalsteps - b->Index) // Scan Pixel to the left
            {
                 setPixelColor(b->group[i], b->Color1);
            }
            else // Fading tail
            {
                 setPixelColor(b->group[i], DimColor(getPixelColor(b->group[i])));
            }
        }
        show();
        Increment(b);
}

void Signaling::FadeUpdate(Update_Data *b)
{
        // Calculate linear interpolation between Color1 and Color2
        // Optimise order of operations to minimize truncation error
        uint8_t red = ((Red(b->Color1) * (b->totalsteps - b->Index)) + (Red(b->Color2) * b->Index)) / b->totalsteps;
        uint8_t green = ((Green(b->Color1) * (b->totalsteps - b->Index)) + (Green(b->Color2) * b->Index)) / b->totalsteps;
        uint8_t blue = ((Blue(b->Color1) * (b->totalsteps - b->Index)) + (Blue(b->Color2) * b->Index)) / b->totalsteps;

        ColorSet(b,Color(red, green, blue));
        show();
        Increment(b);
}

void Signaling::ColorSet(Update_Data *p, uint32_t color)
{
        for (int i = 0; i < p->groupLength; i++)
        {
            setPixelColor(p->group[i], color);
        }
        show();
}

// Calculate 50% dimmed version of a color (used by ScannerUpdate)
uint32_t Signaling::DimColor(uint32_t color)
{
        // Shift R, G and B components one bit to the right
        uint32_t dimColor = Color(Red(color) >> 2, Green(color) >> 2, Blue(color) >> 2);
        return dimColor;
}

    // Returns the Red component of a 32-bit color
uint8_t Signaling::Red(uint32_t color)
{
        return (color >> 16) & 0xFF;
}

    // Returns the Green component of a 32-bit color
uint8_t Signaling::Green(uint32_t color)
{
        return (color >> 8) & 0xFF;
}

    // Returns the Blue component of a 32-bit color
uint8_t Signaling::Blue(uint32_t color)
{
        return color & 0xFF;
}

uint32_t Signaling::Wheel(byte WheelPos)
{
        WheelPos = 255 - WheelPos;
        if(WheelPos < 85)
        {
            return Color(255 - WheelPos * 3, 0, WheelPos * 3);
        }
        else if(WheelPos < 170)
        {
            WheelPos -= 85;
            return Color(0, WheelPos * 3, 255 - WheelPos * 3);
        }
        else
        {
            WheelPos -= 170;
            return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
        }
}

void Signaling::BlinkUpdate(Update_Data *b)
{
    for(int i=0; i < b->groupLength;i++)
    {
        if(getPixelColor(b->group[i]) == 0 )                    //setting LED's to state HIGH
      {
        setPixelColor(b->group[i], b->Color1);
      }
      else if(getPixelColor(b->group[i]) > 0 )                  //setting LED's to LOW state
      {
          setPixelColor(b->group[i],0,0,0,0);
      }
    }
    show();
}

void Signaling::OnOffUpdate(Update_Data *b)
{
    for(int i=0; i < b->groupLength;i++)
    {
      if(getPixelColor(b->group[i]) == 0 && (millis() - b->lastUpdate) > b->off_time)                    //setting LED's to state HIGH
      {b->Interval = b->on_time;
        setPixelColor(b->group[i], b->Color1);
      }
      else if(getPixelColor(b->group[i]) > 0 && (millis() - b->lastUpdate) > b->on_time)                  //setting LED's to LOW state
      {b->Interval = b->off_time;
          setPixelColor(b->group[i],0,0,0,0);
      }
    }
    show();
}

uint32_t Signaling::Brightness(uint32_t color1,uint32_t color2 ,uint32_t intensity)
{
    uint32_t cul = max(max(Red(color2),Blue(color2)),Green(color2));

    uint32_t color = Color((Red(color1)/cul)*intensity,(Green(color1)/cul)*intensity,(Blue(color1)/cul)*intensity);
    return color;
}

void Signaling::PulsatingUpdate(Update_Data *b)
{
    //setPixelColor(10, Brightness(b->Color1, b->Color1, 10));
    uint32_t color = getPixelColor(10);
    uint32_t min1 = min(min(Red(color),Blue(color)),Green(color));
    uint32_t min2 = min(min(Red(b->Color1),Blue(b->Color1)),Green(b->Color1));
    uint32_t max1 = max(max(Red(color),Blue(color)),Green(color));
    uint32_t max2 = max(max(Red(b->Color1),Blue(b->Color1)),Green(b->Color1));
    setPixelColor(10, Brightness(color, b->Color1, 255));
   /* if( b->LedState == false)
    {
        for(int i = 0; i < b->groupLength; i++)
        {
            setPixelColor(b->group[i], Brightness(color, b->Color1, max1-3));
        }
        if( min1 < 8)
        {
            b->LedState = true;
        }
    }
    else if( b->LedState == true)
    {
        for(int i = 0; i < b->groupLength; i++)
        {
            setPixelColor(b->group[i], Brightness(color, b->Color1, max1+3));
        }
        if( max1 > max2)
        {
            b->LedState = false;
        }
    }*/
    show();
}

void Signaling::LoadingUpdate(Update_Data *b)                   //function for Loading bar
{
    if( b->Index < b->groupLength)
    {
    setPixelColor(b->group[b->Index], b->Color1);
    show();
    Increment(b);
    }
    else if(b->Index >= b->groupLength)
    {
        for( int i = 0; i < b->groupLength; i++)
        {
          setPixelColor(b->group[i], 0, 0, 0, 0);
        }
        show();
        b->Index = 0;

        //Increment(b);
    }

}

void Signaling::StepUpdate(Update_Data *b)                          //function to turn one LED ON at a time in a group
{
    if(b->Index >= b->groupLength)
     {
         b->Index = 0;
     }
     for( int i = 0; i < b->groupLength; i++)
     {
            if( b->Index != i)
            {
                setPixelColor(b->group[i], 0, 0, 0, 0);
            }
            else
            {
                setPixelColor(b->group[i], b->Color1);
            }
     }

     show();
    Increment(b);
}

