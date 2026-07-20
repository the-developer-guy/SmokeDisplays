/*
Pins
A B C D E F
   -   -
| | | | | ⚡
   -   -
| | | | | 💧
   -   -
     4
   5   3
   6   2
     1 

*/

#define DISPLAY_1_B_PINS       ((0b11 << 10) | (0b00 << 8) | (0b00 << 6) | (0b10 << 4) | (0b00 << 2) | (0b00 << 0))
#define DISPLAY_1_C_PINS       ((0b00 << 10) | (0b00 << 8) | (0b10 << 6) | (0b00 << 4) | (0b00 << 2) | (0b11 << 0))
#define DISPLAY_2_A_PINS       ((0b00 << 10) | (0b00 << 8) | (0b00 << 6) | (0b00 << 4) | (0b11 << 2) | (0b10 << 0))
#define DISPLAY_2_B_PINS       ((0b00 << 10) | (0b00 << 8) | (0b00 << 6) | (0b11 << 4) | (0b00 << 2) | (0b10 << 0))
#define DISPLAY_2_C_PINS       ((0b00 << 10) | (0b00 << 8) | (0b11 << 6) | (0b00 << 4) | (0b00 << 2) | (0b10 << 0))
#define DISPLAY_2_D_PINS       ((0b00 << 10) | (0b11 << 8) | (0b00 << 6) | (0b00 << 4) | (0b00 << 2) | (0b10 << 0))
#define DISPLAY_2_E_PINS       ((0b11 << 10) | (0b00 << 8) | (0b00 << 6) | (0b00 << 4) | (0b00 << 2) | (0b10 << 0))
#define DISPLAY_2_F_PINS       ((0b00 << 10) | (0b00 << 8) | (0b00 << 6) | (0b00 << 4) | (0b10 << 2) | (0b11 << 0))
#define DISPLAY_2_G_PINS       ((0b00 << 10) | (0b00 << 8) | (0b00 << 6) | (0b11 << 4) | (0b10 << 2) | (0b00 << 0))
#define DISPLAY_3_A_PINS       ((0b00 << 10) | (0b00 << 8) | (0b11 << 6) | (0b00 << 4) | (0b10 << 2) | (0b00 << 0))
#define DISPLAY_3_B_PINS       ((0b00 << 10) | (0b11 << 8) | (0b00 << 6) | (0b00 << 4) | (0b10 << 2) | (0b00 << 0))
#define DISPLAY_3_C_PINS       ((0b11 << 10) | (0b00 << 8) | (0b00 << 6) | (0b00 << 4) | (0b10 << 2) | (0b00 << 0))
#define DISPLAY_3_D_PINS       ((0b00 << 10) | (0b00 << 8) | (0b00 << 6) | (0b10 << 4) | (0b00 << 2) | (0b11 << 0))
#define DISPLAY_3_E_PINS       ((0b00 << 10) | (0b00 << 8) | (0b00 << 6) | (0b10 << 4) | (0b11 << 2) | (0b00 << 0))
#define DISPLAY_3_F_PINS       ((0b00 << 10) | (0b00 << 8) | (0b11 << 6) | (0b10 << 4) | (0b00 << 2) | (0b00 << 0))
#define DISPLAY_3_G_PINS       ((0b00 << 10) | (0b11 << 8) | (0b00 << 6) | (0b10 << 4) | (0b00 << 2) | (0b00 << 0))
#define DISPLAY_THUNDER_PINS   ((0b00 << 10) | (0b00 << 8) | (0b10 << 6) | (0b00 << 4) | (0b11 << 2) | (0b00 << 0))
#define DISPLAY_DROPLET_PINS   ((0b00 << 10) | (0b00 << 8) | (0b10 << 6) | (0b11 << 4) | (0b00 << 2) | (0b00 << 0)) 
#define DISPLAY_NUM_1_PINS     ((0b10 << 10) | (0b00 << 8) | (0b00 << 6) | (0b00 << 4) | (0b00 << 2) | (0b11 << 0)) 
#define DISPLAY_NUM_2_PINS     ((0b00 << 10) | (0b10 << 8) | (0b11 << 6) | (0b11 << 4) | (0b00 << 2) | (0b00 << 0)) 
#define DISPLAY_NUM_3_PINS     ((0b00 << 10) | (0b10 << 8) | (0b00 << 6) | (0b00 << 4) | (0b00 << 2) | (0b11 << 0)) 
#define DISPLAY_NUM_4_PINS     ((0b11 << 10) | (0b11 << 8) | (0b10 << 6) | (0b00 << 4) | (0b00 << 2) | (0b00 << 0)) 
#define DISPLAY_NUM_5_PINS     ((0b10 << 10) | (0b11 << 8) | (0b00 << 6) | (0b00 << 4) | (0b00 << 2) | (0b00 << 0)) 
#define DISPLAY_NUM_6_PINS     ((0b10 << 10) | (0b00 << 8) | (0b00 << 6) | (0b11 << 4) | (0b11 << 2) | (0b00 << 0)) 

/**
7-segment display segment definition

 A
F B
 G
E C
 D
*/

// Individual segments

#define DISPLAY_1_B_BITMASK       ((1ul) << 0)
#define DISPLAY_1_C_BITMASK       ((1ul) << 1)

#define DISPLAY_2_A_BITMASK       ((1ul) << 2)
#define DISPLAY_2_B_BITMASK       ((1ul) << 3)
#define DISPLAY_2_C_BITMASK       ((1ul) << 4)
#define DISPLAY_2_D_BITMASK       ((1ul) << 5)
#define DISPLAY_2_E_BITMASK       ((1ul) << 6)
#define DISPLAY_2_F_BITMASK       ((1ul) << 7)
#define DISPLAY_2_G_BITMASK       ((1ul) << 8)

#define DISPLAY_3_A_BITMASK       ((1ul) << 9)
#define DISPLAY_3_B_BITMASK       ((1ul) << 10)
#define DISPLAY_3_C_BITMASK       ((1ul) << 11)
#define DISPLAY_3_D_BITMASK       ((1ul) << 12)
#define DISPLAY_3_E_BITMASK       ((1ul) << 13)
#define DISPLAY_3_F_BITMASK       ((1ul) << 14)
#define DISPLAY_3_G_BITMASK       ((1ul) << 15)

#define DISPLAY_THUNDER_BITMASK   ((1ul) << 16)
#define DISPLAY_DROPLET_BITMASK   ((1ul) << 17)
#define DISPLAY_NUM_1_BITMASK     ((1ul) << 18)
#define DISPLAY_NUM_2_BITMASK     ((1ul) << 19)
#define DISPLAY_NUM_3_BITMASK     ((1ul) << 20)
#define DISPLAY_NUM_4_BITMASK     ((1ul) << 21)
#define DISPLAY_NUM_5_BITMASK     ((1ul) << 22)
#define DISPLAY_NUM_6_BITMASK     ((1ul) << 23)

// Numbers

#define DISPLAY_1_NUM_1 (DISPLAY_1_B_BITMASK | DISPLAY_1_C_BITMASK)

#define DISPLAY_2_NUM_0 (DISPLAY_2_A_BITMASK | DISPLAY_2_B_BITMASK | DISPLAY_2_C_BITMASK | DISPLAY_2_D_BITMASK | DISPLAY_2_E_BITMASK | DISPLAY_2_F_BITMASK)
#define DISPLAY_2_NUM_1 (DISPLAY_2_B_BITMASK | DISPLAY_2_C_BITMASK)
#define DISPLAY_2_NUM_2 (DISPLAY_2_A_BITMASK | DISPLAY_2_B_BITMASK | DISPLAY_2_D_BITMASK | DISPLAY_2_E_BITMASK | DISPLAY_2_G_BITMASK)
#define DISPLAY_2_NUM_3 (DISPLAY_2_A_BITMASK | DISPLAY_2_B_BITMASK | DISPLAY_2_C_BITMASK | DISPLAY_2_D_BITMASK | DISPLAY_2_G_BITMASK)
#define DISPLAY_2_NUM_4 (DISPLAY_2_B_BITMASK | DISPLAY_2_C_BITMASK | DISPLAY_2_F_BITMASK | DISPLAY_2_G_BITMASK)
#define DISPLAY_2_NUM_5 (DISPLAY_2_A_BITMASK | DISPLAY_2_C_BITMASK | DISPLAY_2_D_BITMASK | DISPLAY_2_F_BITMASK | DISPLAY_2_G_BITMASK)
#define DISPLAY_2_NUM_6 (DISPLAY_2_A_BITMASK | DISPLAY_2_C_BITMASK | DISPLAY_2_D_BITMASK | DISPLAY_2_E_BITMASK | DISPLAY_2_F_BITMASK | DISPLAY_2_G_BITMASK)
#define DISPLAY_2_NUM_7 (DISPLAY_2_A_BITMASK | DISPLAY_2_B_BITMASK | DISPLAY_2_C_BITMASK)
#define DISPLAY_2_NUM_8 (DISPLAY_2_A_BITMASK | DISPLAY_2_B_BITMASK | DISPLAY_2_C_BITMASK | DISPLAY_2_D_BITMASK | DISPLAY_2_E_BITMASK | DISPLAY_2_F_BITMASK | DISPLAY_2_G_BITMASK)
#define DISPLAY_2_NUM_9 (DISPLAY_2_A_BITMASK | DISPLAY_2_B_BITMASK | DISPLAY_2_C_BITMASK | DISPLAY_2_D_BITMASK | DISPLAY_2_F_BITMASK | DISPLAY_2_G_BITMASK)

#define DISPLAY_3_NUM_0 (DISPLAY_3_A_BITMASK | DISPLAY_3_B_BITMASK | DISPLAY_3_C_BITMASK | DISPLAY_3_D_BITMASK | DISPLAY_3_E_BITMASK | DISPLAY_3_F_BITMASK)
#define DISPLAY_3_NUM_1 (DISPLAY_3_B_BITMASK | DISPLAY_3_C_BITMASK)
#define DISPLAY_3_NUM_2 (DISPLAY_3_A_BITMASK | DISPLAY_3_B_BITMASK | DISPLAY_3_D_BITMASK | DISPLAY_3_E_BITMASK | DISPLAY_3_G_BITMASK)
#define DISPLAY_3_NUM_3 (DISPLAY_3_A_BITMASK | DISPLAY_3_B_BITMASK | DISPLAY_3_C_BITMASK | DISPLAY_3_D_BITMASK | DISPLAY_3_G_BITMASK)
#define DISPLAY_3_NUM_4 (DISPLAY_3_B_BITMASK | DISPLAY_3_C_BITMASK | DISPLAY_3_F_BITMASK | DISPLAY_3_G_BITMASK)
#define DISPLAY_3_NUM_5 (DISPLAY_3_A_BITMASK | DISPLAY_3_C_BITMASK | DISPLAY_3_D_BITMASK | DISPLAY_3_F_BITMASK | DISPLAY_3_G_BITMASK)
#define DISPLAY_3_NUM_6 (DISPLAY_3_A_BITMASK | DISPLAY_3_C_BITMASK | DISPLAY_3_D_BITMASK | DISPLAY_3_E_BITMASK | DISPLAY_3_F_BITMASK | DISPLAY_3_G_BITMASK)
#define DISPLAY_3_NUM_7 (DISPLAY_3_A_BITMASK | DISPLAY_3_B_BITMASK | DISPLAY_3_C_BITMASK)
#define DISPLAY_3_NUM_8 (DISPLAY_3_A_BITMASK | DISPLAY_3_B_BITMASK | DISPLAY_3_C_BITMASK | DISPLAY_3_D_BITMASK | DISPLAY_3_E_BITMASK | DISPLAY_3_F_BITMASK | DISPLAY_3_G_BITMASK)
#define DISPLAY_3_NUM_9 (DISPLAY_3_A_BITMASK | DISPLAY_3_B_BITMASK | DISPLAY_3_C_BITMASK | DISPLAY_3_D_BITMASK | DISPLAY_3_F_BITMASK | DISPLAY_3_G_BITMASK)

// Bitmasks to clear display

#define DISPLAY_SEGMENTS_BITMASK    (DISPLAY_1_B_BITMASK | DISPLAY_1_C_BITMASK | \
    DISPLAY_2_A_BITMASK | DISPLAY_2_B_BITMASK | DISPLAY_2_C_BITMASK | DISPLAY_2_D_BITMASK | \
    DISPLAY_2_E_BITMASK | DISPLAY_2_F_BITMASK | DISPLAY_2_G_BITMASK | \
    DISPLAY_3_A_BITMASK | DISPLAY_3_B_BITMASK | DISPLAY_3_C_BITMASK | DISPLAY_3_D_BITMASK | \
    DISPLAY_3_E_BITMASK | DISPLAY_3_F_BITMASK | DISPLAY_3_G_BITMASK)
#define DISPLAY_NUMBERS_BITMASK     (DISPLAY_NUM_1_BITMASK | DISPLAY_NUM_2_BITMASK | DISPLAY_NUM_3_BITMASK | DISPLAY_NUM_4_BITMASK | DISPLAY_NUM_5_BITMASK | DISPLAY_NUM_6_BITMASK)
