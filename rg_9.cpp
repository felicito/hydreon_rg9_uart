/**
 * @file rg_9.cpp
 * @author Felícito Manzano (felicito.manzano@detektor.com.sv)
 * @brief 
 * @version 0.1
 * @date 2020-09-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

extern const const char RG9_QUERY[1];
extern const char RG9_KILL[1];
extern const char RG9_POLLING_MODE[1];
extern const char RG9_CONTINUOUS_MODE[1];

extern const char RG9_RESET[5];
extern const char RG9_LENS_BAD[7];
extern const char RG9_EMITTER_SAT[5];


extern bool rg9_query(BufferedSerial *puertoCOM) {
    puertoCOM->printf("%s\n\r", RG9_QUERY);
    return(true);
}

extern bool rg9_set_pollingMode(BufferedSerial *puertoCOM) {
    puertoCOM->printf("%s\n\r", RG9_POLLING_MODE);
    return(true);   
}

extern bool rg9_set_continuousMode(BufferedSerial *puertoCOM) {
    puertoCOM->printf("%s\n\r", RG9_CONTINUOUS_MODE);
    return(true);
}

extern int read_rg9_uart(BufferedSerial *puertoCOM, char m_buffer[SIZE_BUFFER]) {
  int w = 0;
  while (puertoCOM -> readable()) {
        char incoming_char = puertoCOM -> getc();
        m_buffer[w] = incoming_char;
        w++;
    }
    m_buffer[w] = '\0';
    return(w);
}

extern int rg9_parse(char m_buffer[SIZE_BUFFER]) {
    int m_buffer_length;
    int rg9_answerid;
    char *pch;
    /* Values for RG9 rg9_answerid
        0 => R0 ... 7 => R7
        8 polling mode
        9 continuous mode
        10 Reset
        11 LensBad
        12 EmSat */ 

    m_buffer_lenth = -1;

    m_buffer_length = strlen(m_buffer);
    if (m_buffer_length == 1) { // Answer from a command
        pch = strchr(m_buffer,'p');
        if (pch!=NULL) {
            rg9_answerid = 8;
            return(rg9_answerid);
        } else {
            pch = strchr(m_buffer,'c');
            if (pch!=NULL) {
                rg9_answerid = 9;
                return(rg9_answerid);
            }
        }
    } else if (m_buffer_length == 3) { // 
        pch = strchr(m_buffer,'R');
        if (pch!=NULL) {
            rg9_answerid = (int)(m_buffer_length[3] - 48); // ascii 0 = 48
            return(rg9_answerid);
        }
    } else { // Other
        pch = strstr(m_buffer, RG9_RESET);
        if (pch!=NULL) {
            rg9_anwerid = 10;
            return(rg9_answerid);
        }      
        
        pch = strstr(m_buffer, RG9_LENS_BAD);
        if (pch!=NULL) {
            rg9_anwerid = 11;
        return(rg9_answerid);

        pch = strstr(m_buffer, RG9_EMITTER_SAT);
        if (pch!=NULL) {
            rg9_anwerid = 12;
            return(rg9_answerid);
        }
    }
    return(rg9_answerid);
}




