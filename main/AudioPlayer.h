#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <SD.h>
#include "driver/i2s.h"

#define SD_CS          5
#define I2S_DOUT      22
#define I2S_BCLK      26
#define I2S_LRC       25
#define I2S_NUM       I2S_NUM_0 
#define NUM_BYTES_TO_READ_FROM_FILE 1024

// Complete definition of the struct
struct WavHeader_Struct {
    char RIFFSectionID[4];
    uint32_t Size;
    char RiffFormat[4];
    char FormatSectionID[4];
    uint32_t FormatSize;
    uint16_t FormatID;
    uint16_t NumChannels;
    uint32_t SampleRate;
    uint32_t ByteRate;
    uint16_t BlockAlign;
    uint16_t BitsPerSample;
    char DataSectionID[4];
    uint32_t DataSize;
};

extern File WavFile;
extern struct WavHeader_Struct WavHeader;

void setupAudio();
void loopAudio();
void PlayWav();
uint16_t ReadFile(byte* Samples);
bool FillI2SBuffer(byte* Samples, uint16_t BytesInBuffer);
void SDCardInit();
bool ValidWavData(struct WavHeader_Struct* Wav);
void DumpWAVHeader(struct WavHeader_Struct* Wav);
void PrintData(const char* Data, uint8_t NumBytes);

#endif // AUDIOPLAYER_H
