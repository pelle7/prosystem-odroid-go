#ifndef ODROID_DISPLAY_EMU_IMPL
void ili9341_write_frame_atari7800(uint8_t* buffer, uint16_t* palette);
#else

void ili9341_write_frame_atari7800(uint8_t* buffer, uint16_t* palette)
{
    static const int PROSYSTEM_WIDTH = 320;
    static const int PROSYSTEM_HEIGHT = 240;


    if (buffer == NULL)
    {
        // clear the buffer
        for (int i = 0; i < LINE_BUFFERS; ++i)
        {
            memset(line[i], 0, 320 * sizeof(uint16_t) * LINE_COUNT);
        }

        // clear the screen
        send_reset_drawing(0, 0, 320, 240);

        for (int y = 0; y < 240; y += LINE_COUNT)
        {
            uint16_t* line_buffer = line_buffer_get();
            send_continue_line(line_buffer, 320, LINE_COUNT);
        }
    }
    else
    {
        send_reset_drawing(0, 0, PROSYSTEM_WIDTH, PROSYSTEM_HEIGHT);

        int src_idx = 0;
        for (int y = 0; y < PROSYSTEM_HEIGHT; y += 5)
        {
            uint16_t* line_buffer = line_buffer_get();
            int dst_idx = 0; //i * 320 * sizeof(uint16_t);

            for (int i = 0; i < 5; ++i)
            {
                for (int x = 0; x < PROSYSTEM_WIDTH; ++x)
                {
                    uint16_t pixel= palette[buffer[src_idx++]];
                    pixel = pixel << 8 | pixel >> 8;

                    line_buffer[dst_idx++] = pixel;
                }
            }

            send_continue_line(line_buffer, 320, 5);
        }
    }
}

#endif
