char* uint8ToCharPtr(uint8_t data) {
    char* str = malloc(3 * sizeof(char)); // 2 caratteri per il byte, 1 per il terminatore di stringa
    if (str == NULL) {
        return NULL; // Gestione degli errori per l'allocazione di memoria
    }

    sprintf(str, "%02X", data); // Formatta il dato come esadecimale
    return str;
}

void SPI_Test(){
    initSPI1();
    initLCD();
    
    uint32_t address = 0x0000; // Indirizzo per la scrittura/lettura
    uint8_t dataToWrite = 0xAB; // Dato da scrivere

    writeFlashMem(address, dataToWrite); // Scrivi il dato

    uint8_t dataRead = readFlashMem(address); // Leggi il dato
    char* dataStr = uint8ToCharPtr(dataRead);

    while(1){
        putsLCD(dataStr);
        cmdLCD( 0x80 | 0x00);
        Delayms(50);
    }
     free(dataStr);
}