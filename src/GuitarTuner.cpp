#include "include/SignalProcessing.hpp"
#include "include/MicProcessingAndSpectrumAnalyser.hpp"
#include "include/GuitarTuner.hpp"

#include <thread> // Include the <thread> header

void Cheb_filter(){
    get_audio_input();
    
    // Create a filter_params object to store the filter parameters
    filter_params params;
    std::cout << "Specify filter type (LP, HP): " << std::endl;
    std::cin >> params.filter_type;
    std::cout << "Specify filter order: " << std::endl;
    std::cin >> params.poles;
    std::cout << "Specify filter cutoff frequency (0, 0.5): " << std::endl;
    std::cin >> params.cutoff_frequency;
    std::cout << "Specify filter ripple (0, 29%): " << std::endl;
    std::cin >> params.percent_ripple;
    // Instantiate the filter
    ChebyshevI my_filter(params);
    // Calculate the filter coefficients
    my_filter.calculate_coefficients();


    std::atomic<bool> quit(false); // declare an atomic boolean to control window closing

    std::thread inputThread(display_to_window2, std::ref(quit),my_filter); // create a thread to handle the window and renderer
    std::string input; // declare a string to store the input from the user

    while(!quit){ // loop until the user enters 'Close' or closes the window
        std::cout << "Enter 'b' or 'B' to go back to main menu: ";
        std::cin >> input;
        if (input == "B" || input == "b"){
        quit = true;
        
        }else if(quit == true){ //in case the window is closed by pressing the x button, doesnt display anything to console
            
        }
        else{
            std::cout << "Invalid input" << std::endl;
        }
    }
    
    inputThread.join(); // Wait for input thread to finish
    stop_audio_input(); // closes the microphone and quits SDL2 audio subsystem
    SDL_Quit();  
}
    
