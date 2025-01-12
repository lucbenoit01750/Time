/* DateStrings.cpp
 * Definitions for date strings for use with the Time library
 *
 * Updated for Arduino 1.5.7 18 July 2014
 *
 * No memory is consumed in the sketch if your code does not call any of the string methods
 * You can change the text of the strings, make sure the short strings are each exactly 3 characters 
 * the long strings can be any length up to the constant dt_MAX_STRING_LEN defined in TimeLib.h
 * 
 2025-01-12 : ChipiDev.LBT : Translated labels in french; added weak to functions.
 */

#include <Arduino.h>

// Arduino.h should properly define PROGMEM, PGM_P, strcpy_P, pgm_read_byte, pgm_read_ptr
// But not all platforms define these as they should.  If you find a platform needing these
// defined, or if any this becomes unnecessary as platforms improve, please send a pull req.
#if defined(ESP8266)
#undef PROGMEM
#define PROGMEM
#endif
 
// the short strings for each day or month must be exactly dt_SHORT_STR_LEN
#define dt_SHORT_STR_LEN  3 // the length of short strings

static char buffer[dt_MAX_STRING_LEN+1];  // must be big enough for longest string and the terminating null

const char monthStr0[] PROGMEM = "";
const char monthStr1[] PROGMEM = "Janvier";
const char monthStr2[] PROGMEM = "Février";
const char monthStr3[] PROGMEM = "Mars";
const char monthStr4[] PROGMEM = "Avril";
const char monthStr5[] PROGMEM = "Mai";
const char monthStr6[] PROGMEM = "Juin";
const char monthStr7[] PROGMEM = "Juillet";
const char monthStr8[] PROGMEM = "Août";
const char monthStr9[] PROGMEM = "Septembre";
const char monthStr10[] PROGMEM = "Octobre";
const char monthStr11[] PROGMEM = "Novembre";
const char monthStr12[] PROGMEM = "Décembre";

const PROGMEM char * const PROGMEM monthNames_P[] =
{
    monthStr0,monthStr1,monthStr2,monthStr3,monthStr4,monthStr5,monthStr6,
    monthStr7,monthStr8,monthStr9,monthStr10,monthStr11,monthStr12
};

const char monthShortNames_P[] PROGMEM = "ErrJanFebMarAprMayJunJulAugSepOctNovDec";

const char dayStr0[] PROGMEM = "Err";
const char dayStr1[] PROGMEM = "Dimanche";
const char dayStr2[] PROGMEM = "Lundi";
const char dayStr3[] PROGMEM = "Mardi";
const char dayStr4[] PROGMEM = "Mercredi";
const char dayStr5[] PROGMEM = "Jeudi";
const char dayStr6[] PROGMEM = "Vendredi";
const char dayStr7[] PROGMEM = "Samedi";

const PROGMEM char * const PROGMEM dayNames_P[] =
{
   dayStr0,dayStr1,dayStr2,dayStr3,dayStr4,dayStr5,dayStr6,dayStr7
};

const char dayShortNames_P[] PROGMEM = "Errdimlunmarmerjeuvensam";

/* functions to return date strings */
/* LBT : added __attribute__((weak)) */
__attribute__((weak)) char* monthStr(uint8_t month)
{
    strcpy_P(buffer, (PGM_P)pgm_read_ptr(&(monthNames_P[month])));
    return buffer;
}


__attribute__((weak)) char* monthShortStr(uint8_t month)
{
   for (int i=0; i < dt_SHORT_STR_LEN; i++)      
      buffer[i] = pgm_read_byte(&(monthShortNames_P[i+ (month*dt_SHORT_STR_LEN)]));  
   buffer[dt_SHORT_STR_LEN] = 0;
   return buffer;
}

__attribute__((weak)) char* dayStr(uint8_t day) 
{
   strcpy_P(buffer, (PGM_P)pgm_read_ptr(&(dayNames_P[day])));
   return buffer;
}

__attribute__((weak)) char* dayShortStr(uint8_t day)  
{
   uint8_t index = day*dt_SHORT_STR_LEN;
   for (int i=0; i < dt_SHORT_STR_LEN; i++)      
      buffer[i] = pgm_read_byte(&(dayShortNames_P[index + i]));  
   buffer[dt_SHORT_STR_LEN] = 0; 
   return buffer;
}
