

#include <SDL2/SDL.h>
#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <complex>

// Declare function prototypes //
int make_window(); // initialize SDL2 subsystems to create window and renderer
int destroy_window(); // destroy window and renderer and quit SDL2 subsystems
int get_audio_input(); // initialize SDL2 audio subsystem and gets audio input from microphone
void audioCallback(void* userdata, Uint8* stream, int len); // callback function for audio device
int stop_audio_input(); // closes the microphone and quits SDL2 audio subsystem
void update_window(std::vector<std::complex<double>>& vector, int size); // updates the window with the audio data from transformed_buffer_complex vector
void display_to_window(std::atomic<bool>& quit); // handles everything needed to create and update window, its done in a different thread
void fft(std::vector<std::complex<double>>& vector); // performs the fft on the audio data

int Show_spectrum(); //initialises sdl and gets audio input and transforms it and creates window to display data
// also handles the closing of the window and the microphone by user input or closing window

