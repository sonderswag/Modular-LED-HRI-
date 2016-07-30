#ifndef LIGHTPARAMETER_h
#define LIGHTPARAMETER_h

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/** \brief ActivePattern- Pattern types supported
 */
enum  ActivePattern { NO_PAT,
                      RAINBOW_CYCLE,
                      THEATER_CHASE,
                      COLOR_WIPE,
                      SCANNER,
                      FADE,
                      BLINK,
                      ON_AND_OFF,
                      PULSATING,
                      LOADING,
                      STEP
                      };

/** \brief Direction Pattern directions supported
 */
enum  Direction { FORWARD,/**< Forward direction */
                  REVERSE/**< Reverse direction */
                  };


/** \struct LightParameter
 * \brief Responsible for holding values that define a particular pattern
 */

struct LightParameter{
ActivePattern pattern;      /**< This variable holds one of the supported patterns */
Direction direction;        /**< Specifies the direction in which the pattern will run */

unsigned long startTime;    /**< Specifies the start time of the pattern */
unsigned long stopTime;     /**< Specifies the stop time of the pattern( the calculation of stop time varies from pattern to pattern) */
unsigned long cycles;       /**< Specifies the number of times the pattern is supposed to run*/

int index;                  /**< Specifies the Index from which the pattern is suppose to start from */
unsigned long onTime;       /**< This variable is Specifically used for only On_AND_OFF pattern. Specifies the time for which the LED's should be turned on */
unsigned long offTime;      /**< This variable is Specifically used for only On_AND_OFF pattern. Specifies the time for which the LED's should be off */
int totalsteps;             /**< Keeps track of the current color in the RAINBOW_CYCLE pattern and total no of steps in a particular cycle*/
int brightness;             /**< Used to set the brightness of the LED's */

uint32_t Color1;            /**< Used to set the color of the pattern(used by majority of the patterns) */
uint32_t Color2;            /**< Used to set the 2nd color of the pattern(in this library only THEATER_CHASE uses this parameter) */

unsigned long interval;     /**< Used to set the time for which 1 cycle will run */
unsigned long lastupdate;   /**< Specifies the time at which the pattern was last updated */

char complete;              /**<  Specifies whether or not the pattern is completed*/
bool ledstate;

int group[100];             /**<  Stores the ID's of group of LED's in a pattern*/
int grouplength;            /**<  Specifies the number of LED's that are part of a pattern*/



LightParameter();

LightParameter(ActivePattern Pattern, Direction dir, unsigned long start, int cycle, int Index,
                                unsigned long on, unsigned long off, int Brightness, uint32_t color1, uint32_t color2,
                                unsigned long Interval, int g[], int length);

void initialize(ActivePattern Pattern, Direction dir, unsigned long start, int cycle, int Index,
                unsigned long on, unsigned long off, int Brightness, uint32_t color1, uint32_t color2, unsigned long Interval,
                int g[], int length);
};


#endif // LightParameter_h

