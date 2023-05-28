#include <stdio.h>
#include<windows.h>
 /* function to find pressed key */
#define write_port LATB  /* latch register to write data on port */
#define read_port PORTB  /* PORT register to read data of port */
#define Direction_Port TRISB

/* KEYPAD_ROW1 */
//#define TRIS_KEYPAD_COL1 TRISB.RB0
//#define PORT_KEYPAD_COL1 PORTB.RB0
///* KEYPAD_ROW2 */
//#define TRIS_KEYPAD_COL2 TRISB.RB1
//#define PORT_KEYPAD_COL2 PORTB.RB1
///* KEYPAD_ROW3 */
//#define TRIS_KEYPAD_COL3 TRISB.RB2
//#define PORT_KEYPAD_COL3 PORTB.RB2
///* KEYPAD_ROW4 */
//#define TRIS_KEYPAD_COL4 TRISB.RB3
//#define PORT_KEYPAD_COL4 PORTB.RB3
///* KEYPAD_COL1 */
//#define TRIS_KEYPAD_ROW1 TRISB.RB4
//#define PORT_KEYPAD_ROW1 PORTB.RB4
///* KEYPAD_COL2 */
//#define TRIS_KEYPAD_ROW2 TRISB.RB5
//#define PORT_KEYPAD_ROW2 PORTB.RB5
///* KEYPAD_COL3 */
//#define TRIS_KEYPAD_ROW3 TRISB.RB6
//#define PORT_KEYPAD_ROW3 PORTB.RB6
///* KEYPAD_COL4 */
//#define TRIS_KEYPAD_ROW4 TRISB.RB7
//#define PORT_KEYPAD_ROW4 PORTB.RB7
//#define UART_BAUD 9600
//#define _XTAL_FREQ 10000000
//
//
//void KEYPAD_Init1(void) {
//
//    /* Rows are input */
//    TRIS_KEYPAD_ROW1 = 1;
//    TRIS_KEYPAD_ROW2 = 1;
//    TRIS_KEYPAD_ROW3 = 1;
//    TRIS_KEYPAD_ROW4 = 1;
//    /* Cols are output */
//    TRIS_KEYPAD_COL1 = 0;
//    TRIS_KEYPAD_COL2 = 0;
//    TRIS_KEYPAD_COL3 = 0;
//    TRIS_KEYPAD_COL4 = 0;
//
//    PORT_KEYPAD_ROW1 = 0;
//    PORT_KEYPAD_ROW2 = 0;
//    PORT_KEYPAD_ROW3 = 0;
//    PORT_KEYPAD_ROW4 = 0;
//    PORT_KEYPAD_COL1 = 0;
//    PORT_KEYPAD_COL2 = 0;
//    PORT_KEYPAD_COL3 = 0;
//    PORT_KEYPAD_COL4 = 0;
//}
//
//int KEYPAD_Read(void) {
//
//    /* Start the scanning process */
//    /* Set only COL1 to 1 and read each row one by one until finding the pressed key */
//    PORT_KEYPAD_COL1=1; PORT_KEYPAD_COL2=0;
//    PORT_KEYPAD_COL3=0; PORT_KEYPAD_COL4=0;
//    if(PORT_KEYPAD_ROW1) return 1; if(PORT_KEYPAD_ROW2) return 4;
//    if(PORT_KEYPAD_ROW3) return 7; if(PORT_KEYPAD_ROW4) return 14;
//    delay_us(10);
//    /* Set only COL2 to 1 and read each row one by one until finding the pressed key */
//    PORT_KEYPAD_COL1=0; PORT_KEYPAD_COL2=1;
//    PORT_KEYPAD_COL3=0; PORT_KEYPAD_COL4=0;
//    if(PORT_KEYPAD_ROW1) return 2; if(PORT_KEYPAD_ROW2) return 5;
//    if(PORT_KEYPAD_ROW3) return 8; if(PORT_KEYPAD_ROW4) return 0;
//    delay_us(10);
//    /* Set only COL3 to 1 and read each row one by one until finding the pressed key */
//    PORT_KEYPAD_COL1=0; PORT_KEYPAD_COL2=0;
//    PORT_KEYPAD_COL3=1; PORT_KEYPAD_COL4=0;
//    if(PORT_KEYPAD_ROW1) return 3; if(PORT_KEYPAD_ROW2) return 6;
//    if(PORT_KEYPAD_ROW3) return 9; if(PORT_KEYPAD_ROW4) return 15;
//    delay_us(10);
//    /* Set only COL4 to 1 and read each row one by one until finding the pressed key */
//    PORT_KEYPAD_COL1=0; PORT_KEYPAD_COL2=0;
//    PORT_KEYPAD_COL3=0; PORT_KEYPAD_COL4=1;
//    if(PORT_KEYPAD_ROW2) return 11; if(PORT_KEYPAD_ROW1) return 10;
//    if(PORT_KEYPAD_ROW3) return 12; if(PORT_KEYPAD_ROW4) return 13;
//    delay_us(10);
//
//    return 0xFF; /* Not pressed condition */
//}
//
//char KEYPAD_KeyToChar (int key_number) {
//    /* If number is from 0 to 9, convert to ASCII character by adding 0x30 */
//    if (key_number < 10) return key_number + 0x30;
//    /* If number is greater than 9, it is alphabet and symbol */
//    if (key_number == 10) return 'A'; /* Convert to ASCII A */
//    if (key_number == 11) return 'B'; /* Convert to ASCII B */
//    if (key_number == 12) return 'C'; /* Convert to ASCII C */
//    if (key_number == 13) return 'D'; /* Convert to ASCII D */
//    if (key_number == 14) return '*'; /* Convert to ASCII * */
//    if (key_number == 15) return '#'; /* Convert to ASCII # */
//    return 0; /* No key pressed, Return null */
//}
//
//int KEYPAD_ReadWaitUntilRelease(void) {
//
//    /* The pressed key. */
//    int pressed_key = 0xFF;
//    /* Wait until the key is pressed. */
//    do {
//        pressed_key = KEYPAD_Read();
//    }
//    while (pressed_key == 0xFF);
//    /* Wait until the key is released. */
//    while (KEYPAD_Read() != 0xFF);
//    return pressed_key;
//}
//
//
//unsigned char keyfind();
//unsigned char col_loc,rowloc,temp_col;
//
//unsigned char keypad[4][4]= {'7','8','9','/',
//                             '4','5','6','*',
//                             '1','2','3','-',
//                             ' ','0','=','+'};
//typedef union { unsigned char byte;
//        struct {
//                unsigned char bit0: 1;
//                unsigned char bit1: 1;
//                unsigned char bit2: 1;
//                unsigned char bit3: 1;
//                unsigned char bit4: 1;
//                unsigned char bit5: 1;
//                unsigned char bit6: 1;
//                unsigned char bit7: 1;
//        };
//        struct{
//                unsigned char lowNibble: 4;
//                unsigned char highNibble: 4;
//        };
//} MyByte;
//
//
//void lcd_print(unsigned char dat){
//    MyByte a;
//    a.byte = dat;
//    LATA.B5 = 1;
//    nop();
//    LATD.B7 = a.bit7;
//    LATD.B6 = a.bit6;
//    LATD.B5 = a.bit5;
//    LATD.B4 = a.bit4;
//    nop();
//    LATA.B5 = 0;
//    nop();
//    LATA.B5 = 1;
//    nop();
//    LATD.B7 = a.bit3;
//    LATD.B6 = a.bit2;
//    LATD.B5 = a.bit1;
//    LATD.B4 = a.bit0;
//    nop();
//    LATA.B5 = 0;
//    nop();
//}
//
//void lcd_char(unsigned char dat){
//    LATA.B4 = 1;
//    delay_ms(1);
//    lcd_print(dat);
//}
//
//void lcd_command(unsigned char cmd){
//    LATA.B4 = 0;
//    delay_ms(1);
//    lcd_print(cmd);
//}
//
//void lcd_string(char *str){
//    unsigned char i = 0;
//
//    while(str[i] != '\0'){
//        lcd_char(str[i]);
//        i++;
//    }
//}
//
//void LCD_Command_first(){
//    LATA.B4 = 0;
//    LATA.B5 = 1;
//    delay_ms(1);
//    LATD.B7 = 0;
//    LATD.B6 = 0;
//    LATD.B5 = 1;
//    LATD.B4 = 1;
//    TRISA.B5 = 0;
//    delay_ms(1);
//}
//
//void lcd_init1(){
//        ADCON1 = 0b0001111;
//
//        TRISA.B5 = 0;
//        TRISA.B4 = 0;
//
//        TRISD = 0;
//        delay_ms(20);
//
//        LCD_Command_first();
//        delay_us(40);
//        LCD_Command_first();
//        delay_us(40);
//        LCD_Command_first();
//        lcd_Command(0b00101000);
//        delay_ms(2);
//        lcd_Command(0b00001111);
//        delay_ms(2);
//        lcd_Command(0b00000001);
//        delay_ms(2);
//        lcd_Command(0b00000110);
//}
//
//void lcdr(char a[5])                  // Auxiliary Function - LCD Return (lcdr)
//{
////     TRISD = 0x00;
////     Lcd_Cmd(_LCD_CLEAR);
////     LCD_out_cp(a);
////     TRISD = 0XFF;
//       lcd_string(a)      ;
//}
//void start_second_line(){
// lcd_init1();
//  lcd_Command(0b10100000);  lcd_string("77777777");
//}
//void delete_all_on_first_line(){
//      lcd_command(0b00000000);
//}
//void delete_prev_elem(){
// lcd_command(0b0000100);
// lcd_char(' '); lcd_command(0b000000110);
// lcd_char(' '); lcd_command(0b0000100);
// lcd_char(' '); lcd_command(0b000000110);
//}
//
//void uart_initialize(void)
//{
//        unsigned char dummy = 0;
//        TXSTA.BRGH = 0;                        // Select low speed baud rate, if we are using SPBRGH.
//        BAUDCON.BRG16 = 1;                //Uses SPBRGH and SPBRG for baudrate generation
//        SPBRGH = ( (_XTAL_FREQ / 16 / UART_BAUD) - 1 ) /256;        //calculate and assign the higher byte for SPBRGH
//        SPBRG = ((_XTAL_FREQ / 16 / UART_BAUD) - 1)%256 ;        // Configure the baud rate.
//        RCSTA.SPEN = 1;        // Enable serial port.
//        RCSTA.CREN = 1;        // Enable reception.
//        TXSTA.TXEN = 1;        // Enable transmission.
//        dummy = RCREG;                // dummy read, to clear the receive buffer
//        dummy = RCREG;
//}
//
//void uart_transmit(unsigned char uc_data)
//{
//        // Wait until the transmit buffer is ready for new data.
//        while (PIR1.TXIF == 0);
//
//        // Transmit the data.
//        TXREG = uc_data;
//}
//
//unsigned char uc_uart_receive(void)
//{
//        // If there is overrun error...
//        if (RCSTA.OERR == 1) {
//                // Clear the flag by disable and enable back the reception.
//                RCSTA.CREN = 0;
//                RCSTA.CREN = 1;
//        }
//
//        // Wait until there is data available in the receive buffer.
//        while (PIR1.RCIF == 0);
//
//        // Return the received data.
//        return RCREG;
//}
//void uart_putstr( const char* csz_string)
//{
//        // Loop until the end of string.
//        while (*csz_string != '\0') {
//                uart_transmit(*csz_string);
//
//                // Point to next character.
//                csz_string+=1;
//        }
//}
//
//void test_uart(void)
//{
//        char c_received_data;
//
//        uart_initialize();        //initialize UART
//        // Display the messages on PTK40A LCD
//
//        // Sending message to the PC.
//        uart_putstr("\r\n\nPTK40A Test UART\r\n");
//        uart_putstr("Press any key to echo\r\n");
//        uart_putstr("ENTER to exit\r\n\n");
//
//        do {
//                c_received_data = uc_uart_receive();
//
//  lcd_char(c_received_data);
//                uart_transmit(c_received_data);
//        }
//        while (c_received_data != '\r' && c_received_data != '\n');
//           lcd_string(c_received_data);
//        // Sending message to the PC.
//        uart_putstr("\r\n\nTest Done\r\n");
//
//        // Beep twice to indicate test pass
//        delay_ms(200);
//}
//
//void setrow(int row){
// if (row == 1){
//  lcd_command(0x80);
//  }
//  else if (row == 2) lcd_command(0xC0);
//}

int ButtonPressHandler(char button){
    if (button == '0') return 0;
    if (button == '1') return 1;
    if (button == '2') return 2;
    if (button == '3') return 3;
    if (button == '4') return 4;
    if (button == '5') return 5;
    if (button == '6') return 6;
    if (button == '7') return 7;
    if (button == 'A') return 8;
    if (button == 'B') return 9;
    if (button == 'C') return 10;
    if (button == 'D') return 11;
    if (button == '*') return 12;
    if (button == '#') return 13;

    return 255;
}

int ChangeNumber(int currentNumber, int newNumber){
    return currentNumber * 8 + newNumber;
}

void Error(){
    printf("\nERROR\n");
    exit(23);
}

int Compute(int firstNumber, int secondNumber, int operation){
//    printf("\n Computation of %d, %d, %d")
    if (operation == 0) return firstNumber + secondNumber;
    if (operation == 1) return firstNumber - secondNumber;
    if (operation == 2) return firstNumber * secondNumber;
    if (operation == 3 && secondNumber != 0) return firstNumber / secondNumber;
    Error();
}

int allReleased(const int pressed[14]) {
    for (int i = 0; i < 14; i++) {
        if (pressed[i] == 1) return 0;
    }
    return 1;
}

void main() {
    char line;
    int keypad = 1;
    int button = 20;
    char symbol;
    int firstNumber = 0;
    int firstNumberAmountDigits = 0;
    int secondNumber = 0;
    int secondNumberAmountDigits = 0;
    int operation = -1;
    int result = -1;
    int pressed[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//    lcd_init1();
    //         TRISB = 0XFF;
    //     PORTB = 0XFF;
//    KEYPAD_Init1();

//    while (1) {
    for (int k = 0; k < 105; k++){
//     if (keypad == 1){
//          button = KEYPAD_read();
//          symbol = KEYPAD_KeyToChar(button)  ;
//       }
//       else{
//       uart_initialize();
//          symbol = uc_uart_receive();
//          uart_transmit(symbol);
//       }
//
//        if (symbol == 'A'){
//          setrow(1);
//          keypad = 1;
//          button = 0xff;
//         }
//         if (symbol == 'B'){
//          setrow(2);
//          keypad = 0;
//          button = 0xff;
//         }
//       if (symbol == '0' || symbol == '1' || symbol == '2' || symbol == '3' || symbol == '4' || symbol == '5' || symbol == '6' || symbol == '7' || symbol == '8' || symbol == 'C' || symbol == 'D') lcd_char(symbol);
//
//     delay_ms(100);
//         };
    scanf(" %c", &symbol);

    if (allReleased(pressed) == 1){
        pressed[ButtonPressHandler(symbol)] = 1;

        if (symbol == '*'){
            if (operation == -1){
                firstNumber = 0;
                firstNumberAmountDigits = 0;
            }
            else{
                firstNumber = 0;
                firstNumberAmountDigits = 0;
                secondNumber = 0;
                secondNumberAmountDigits = 0;
                operation = 0;
            }
            printf("\nENTER AGAIN:");
            continue;
        }

        if (firstNumberAmountDigits == 0){
            if (ButtonPressHandler(symbol) > 7) Error();
            else{
                firstNumber = ChangeNumber(firstNumber, ButtonPressHandler(symbol));
                firstNumberAmountDigits += 1;
            }
        }
        else{
            if (firstNumberAmountDigits == 3 && symbol != 'A' && symbol != 'B' && symbol != 'C' && symbol != 'D' && operation == -1) Error();
            else{
                if (operation == -1 && (symbol == 'A' || symbol == 'B' || symbol == 'C' || symbol == 'D')){
                    operation = ButtonPressHandler(symbol) - 8;
                }
                else{
                    if (operation == -1 && ButtonPressHandler(symbol) <= 7){
                        firstNumber = ChangeNumber(firstNumber, ButtonPressHandler(symbol));
                        firstNumberAmountDigits += 1;
                    }
                    else{
                        printf("\n we are here!!!\n");
                        if (operation != -1){
                            if (secondNumberAmountDigits == 3 && symbol != '#') Error();
                            if (secondNumberAmountDigits == 0 && ButtonPressHandler(symbol) > 7) Error();
                            if (secondNumberAmountDigits < 3 && ButtonPressHandler(symbol) <= 7){
                                secondNumber = ChangeNumber(secondNumber, ButtonPressHandler(symbol));
                                secondNumberAmountDigits += 1;
                            }
                            if (secondNumberAmountDigits != 0 && symbol == '#') printf("RESULT %d", Compute(firstNumber, secondNumber, operation));
                        }
//                        else{
//
//                        }
                    }
                }
            }
        }
        printf("\npressed %i %i %i %i %i %i %i %i %i %i %i %i", pressed[0], pressed[1], pressed[2], pressed[3], pressed[4], pressed[5], pressed[6], pressed[7], pressed[8], pressed[9], pressed[10], pressed[11], pressed[12], pressed[13]);

        printf("\nsymbol: %c\n firstNumber: %i\n firstNumberAmount: %i\n secondNumber: %i\n secondNumberAmount: %i\n operation: %i\n ", symbol, firstNumber, firstNumberAmountDigits, secondNumber, secondNumberAmountDigits, operation);

//        pressed = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    }
    for (int i = 0; i < 14; i++){
//      if (ButtonPressHandler(symbol) == 255) pressed[i] = 0;
        if (symbol == 'x' && pressed[i] == 1) {
            pressed[i] = 0;
            printf("\nALL RELEASED\n");
        }
    }

//        _sleep(100);

    }
}
