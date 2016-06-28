#include "Signalling.h"

const byte PIN=6;    //output PWM pin

Signalling::Signalling(uint16_t pixels, uint8_t pin, uint8_t type):Adafruit_NeoPixel(pixels, pin, type){

//OnComplete = callback;
}

// Update the pattern
void Signalling::Update(Update_Data *a)
{

        if((millis() - a->lastUpdate) > a->Interval) // time to update
        {
            a->lastUpdate = millis();
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
         //       case FADE:
         //           FadeUpdate(a);
         //           break;
              /*  case BLINK:
                    BlinkUpdate();
                    break;
                case ON_AND_OFF:
                    OnOffUpdate();
                    break;
                case PULSATING:
                    PulsatingUpdate();
                    break;*/
                default:
                    break;
            }
        }
    }

//change the status of the  pattern
bool Signalling::OnComplete(bool c)
{
    c=true;
    return c;
}
    // Increment the Index and reset at the end
void Signalling::Increment(Update_Data *p)
    {
        if (p->direction == FORWARD)
        {
           p->Index++;
            p->totalsteps++;
           if (p->Index >= p->groupLength)
            {
                p->Index = 0;
                if (p->totalsteps>=(p->groupLength*p->cycles))
                {
                    p->complete=OnComplete(p->complete); // call the comlpetion callback
                }
            }
        }
        else // Direction == REVERSE
        {
            --p->Index;
            if (p->Index <= 0)
            {
                p->Index = p->groupLength-1;
                if (p->totalsteps>=(p->groupLength*p->cycles))
                {
                    p->complete=OnComplete(p->complete); // call the comlpetion callback
                }
            }
        }
    }

// Update the Rainbow Cycle Pattern
void Signalling::RainbowCycleUpdate(Update_Data *b)
    {
        for(int i=0; i< b->groupLength; i++)
        {
            setPixelColor(b->group[i], Wheel(((i * 256 / b->groupLength) + b->Index) & 255));
        }
        show();
        Increment(b);
    }

// Update the Theater Chase Pattern
void Signalling::TheaterChaseUpdate(Update_Data *b)
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
void Signalling::ColorWipeUpdate(Update_Data *b)
    {
        setPixelColor(b->group[b->Index], b->Color1);
        show();
        Increment(b);
    }

    // Update the Scanner Pattern
    void Signalling::ScannerUpdate(Update_Data *b)
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

// Calculate 50% dimmed version of a color (used by ScannerUpdate)
    uint32_t Signalling::DimColor(uint32_t color)
    {
        // Shift R, G and B components one bit to the right
        uint32_t dimColor = Color(Red(color) >> 1, Green(color) >> 1, Blue(color) >> 1);
        return dimColor;
    }

    // Returns the Red component of a 32-bit color
    uint8_t Signalling::Red(uint32_t color)
    {
        return (color >> 16) & 0xFF;
    }

    // Returns the Green component of a 32-bit color
    uint8_t Signalling::Green(uint32_t color)
    {
        return (color >> 8) & 0xFF;
    }

    // Returns the Blue component of a 32-bit color
    uint8_t Signalling::Blue(uint32_t color)
    {
        return color & 0xFF;
    }

    uint32_t Signalling::Wheel(byte WheelPos)
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

