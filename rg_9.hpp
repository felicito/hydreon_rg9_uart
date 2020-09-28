/**
 * @file rg_9.hpp
 * @author Felícito Manzano (felicito.manzano@detektor.com.sv)
 * @brief
 * @version 0.1
 * @date 2020-09-26
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef __RG_9_HPP
#define __RG_9_HPP

    extern const char RG9_QUERY[1];
    extern const char RG9_KILL[1];
    extern const char RG9_POLLING_MODE[1];
    extern const char RG9_CONTINUOUS_MODE[1];
    
    extern const char RG9_RESET[5];
    extern const char RG9_LENS_BAD[7];
    extern const char RG9_EMITTER_SAT[5];
    
    // FUNCTIONS
    bool rg9_query(BufferedSerial *puertoCOM);
    bool rg9_set_pollingMode(BufferedSerial *puertoCOM);
    bool rg9_set_continuousMode(BufferedSerial *puertoCOM);
    int read_rg9_uart(BufferedSerial *puertoCOM, unsigned char m_buffer[64]);
    int rg9_parse(char m_buffer[64]);
    bool rg9_weather(int *current_w, int *previous_w, bool *raining);

#endif // __RG_9_HPP
