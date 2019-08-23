//switch declarations and switches array
const int switch_0 = 10;
const int switch_1 = 11;
const int switch_2 = 12;
const int switch_3 = 13;
const int switches [4] = { switch_0, switch_1, switch_2, switch_3 };
//switch position
int position;
int last_position;
//led color, firebase string
char *color;
char *message;
int hue_sine_center; 
int led_range[3] = {};
int led_switch = 1;
//led declarations
#define LED_PIN    14
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    12
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))
#define BRIGHTNESS 255
#define FRAMES_PER_SECOND  40