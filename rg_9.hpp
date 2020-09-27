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

    // COMMANDS
    const char RG9_QUERY[]              = "R";
    const char RG9_KILL[]               = "K";
    const char RG9_POLLING_MODE[]       = "P";
    const char RG9_CONTINUOUS_MODE[]    = "C";
    
    // INFO
    const char RG9_RESET[]               = "Reset";
    const char RG9_LENS_BAD[]           = "LensBad";
    const char RG9_EMITTER_SAT[]        = "EmSat";

    // FUNCTIONS
    bool rg9_query(BufferedSerial *puertoCOM);
    bool rg9_set_pollingMode(BufferedSerial *puertoCOM);
    bool rg9_set_continuousMode(BufferedSerial *puertoCOM);
    int read_rg9_uart(BufferedSerial *puertoCOM, unsigned char m_buffer[SIZE_BUFFER]);
    int rg9_parse(char m_buffer[SIZE_BUFFER]);


#endif // __RG_9_HPP