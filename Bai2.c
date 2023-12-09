#include <stdio.h>
#include <stdarg.h>

typedef enum {
    LIGHT,
    AIR_CONDITIONER,
    FINGERPRINT_LOCK,
    MUSIC_PLAYER
} DeviceType;

typedef enum {
    ON,
    OFF,
    SET_TEMPERATURE,
    SET_MODE,
    UNLOCK,
    LOCK,
    INCREASE_VOLUME,
    DECREASE_VOLUME,
    CHANGE_TRACK
} CommandType;

void controlDevice(DeviceType device, ...) {
    va_list args;
    va_start(args, device);

    switch (device) {
        case LIGHT:
            switch (va_arg(args, CommandType)) {
                case ON:
                    printf("Light turned ON\n");
                    break;
                case OFF:
                    printf("Light turned OFF\n");
                    break;
                default:
                    printf("Unsupported command for LIGHT\n");
            }
            break;

        case AIR_CONDITIONER:
            switch (va_arg(args, CommandType)) {
                case ON:
                    printf("Air Conditioner turned ON\n");
                    break;
                case OFF:
                    printf("Air Conditioner turned OFF\n");
                    break;
                case SET_TEMPERATURE:
                    printf("Air Conditioner temperature set to %d degrees\n", va_arg(args, int));
                    break;
                case SET_MODE:
                    printf("Air Conditioner mode set\n");
                    break;
                default:
                    printf("Unsupported command for AIR_CONDITIONER\n");
            }
            break;

        case FINGERPRINT_LOCK:
            switch (va_arg(args, CommandType)) {
                case UNLOCK:
                    printf("Fingerprint Lock unlocked\n");
                    break;
                case LOCK:
                    printf("Fingerprint Lock locked\n");
                    break;
                default:
                    printf("Unsupported command for FINGERPRINT_LOCK\n");
            }
            break;

        case MUSIC_PLAYER:
            switch (va_arg(args, CommandType)) {
                case ON:
                    printf("Music Player turned ON\n");
                    break;
                case OFF:
                    printf("Music Player turned OFF\n");
                    break;
                case INCREASE_VOLUME:
                    printf("Music Player volume increased\n");
                    break;
                case DECREASE_VOLUME:
                    printf("Music Player volume decreased\n");
                    break;
                case CHANGE_TRACK:
                    printf("Music Player track changed\n");
                    break;
                default:
                    printf("Unsupported command for MUSIC_PLAYER\n");
            }
            break;

        default:
            printf("Unsupported device type\n");
    }

    va_end(args);
}

int main() {
    controlDevice(LIGHT, ON);
    controlDevice(AIR_CONDITIONER, SET_TEMPERATURE, 24);
    controlDevice(FINGERPRINT_LOCK, UNLOCK);
    controlDevice(MUSIC_PLAYER, ON);
    controlDevice(MUSIC_PLAYER, CHANGE_TRACK);

    return 0;
}
