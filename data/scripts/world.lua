-- Desde este script se ponen los enemigos, la energia, y las plataformas.

function set_world_data(STARTPOINTX, STARTPOINTY, room, world, ene, data, gfx, energy, switch, plat)
    sx = STARTPOINTX
    sy = STARTPOINTY

    if room == 0 then
        create_enemy(ene, gfx, data, 21, 320, 128, 292 + 32, 292, 128, 128, 0, 0, 2, 0, 0, 0, 0, 1)
        create_enemy(ene, gfx, data, 20, 144, 112, 124, 224, 0, 0, 0, 0, 2, 0, 0, 2, 0, 10)
        create_enemy(ene, gfx, data, 36, 336, 80, 300, 444, 0, 0, 0, 0, 2, 1, 0, 6, 0, 1)
        create_enemy(ene, gfx, data, 37, 128, 224, 128, 220, 0, 0, 0, 0, 4, 0, 0, 8, 0, 1)
        create_switch(switch, 514 - STARTPOINTX, 204 - STARTPOINTY, 4, 4, 0)
        set_background_image(world, 1)
        return
    end

    if room == 1 then
        create_enemy(ene, gfx, data, 26, 272 - STARTPOINTX, 204 - STARTPOINTY, 272 - STARTPOINTX, 272 - STARTPOINTY, 204 - STARTPOINTX, 204 - STARTPOINTX, 0, 0, 1, 1, 1, 4, 0, 1)
        create_energy(energy, 288 - STARTPOINTX, 316 - STARTPOINTY, 0)
        create_energy(energy, 336 - STARTPOINTX, 316 - STARTPOINTY, 1)
        create_platform(plat, 0, 128, 256 - 64, 0, 4, 0, 120, 0, 192, 1, 1)
        create_platform(plat, 0, 176, 64, 4, 0, 176, 0, 296, 0, 0, 1)
        create_platform(plat, 3, 352, 256 - 80, 0, 4, 0, 72, 0, 256 - 80, 1, 1)
        set_background_image(world, 1)
        return
    end

    if room == 2 then
        create_enemy(ene, gfx, data, 24, 176 - sx, 84 - sy, 0, 0, 84 - sx, 236 - sy, 0, 0, 1, 0, 2, 0, 8, 1)
        create_enemy(ene, gfx, data, 24, 354 - sx, 92 - sy, 354 - sx, 430, 0, 0, 0, 0, 1, 1, 0, 6, 0, 1)
        set_background_image(world, 1)
        return
    end

    if room == 3 then
        create_enemy(ene, gfx, data, 25, 192 - sx, 140 - sy, 0, 0, 140 - sx, 234 - sy, 0, 0, 1, 0, 1, 0, 6, 1)
        create_enemy(ene, gfx, data, 24, 448 - sx, 92 - sy, 0, 0, 92 - sx, 268 - sy, 0, 0, 1, 0, 0, 0, 4, 1)
        set_background_image(world, 1)
        return
    end

    if room == 4 then
        create_enemy(ene, gfx, data, 9, 80 - sx, 236 - sy, 80 - sx, 240 - sy, 236 - sx, 236 - sy, 0, 0, 1, 1, 0, 6, 0, 1)
        create_enemy(ene, gfx, data, 9, 352 - sx, 204 - sy, -1, 300 - sy, 204 - sx, 300 - sy, 0, 0, 1, 0, 1, 0, 2, 1)
        create_enemy(ene, gfx, data, 9, 470 - sx, 236 - sy, 416 - sx, 528 - sy, 236 - sx, 236 - sy, 0, 0, 1, 1, 0, 2, 0, 1)
        create_enemy(ene, gfx, data, 9, 416 - sx, 300 - sy, 416 - sx, 528 - sy, 300 - sx, 300 - sy, 0, 0, 1, 1, 0, 2, 0, 1)
        create_enemy(ene, gfx, data, 9, 224 - sx, 172 - sy, 224 - sx, 416 - sy, 172 - sx, 172 - sy, 0, 0, 1, 1, 0, 4, 0, 1)
        create_switch(switch, 224 + sx, 116 + sy, 4, 4, 1)
        set_background_image(world, 1)
        return
    end

    if room == 5 then
        create_enemy(ene, gfx, data, 10, 64, 208, 0, 128, 0, 0, 0, 0, 1, 1, 0, 8, 0, 1)
        create_enemy(ene, gfx, data, 10, 448, 80, 228, 448, 0, 0, 0, 0, 1, 1, 0, 4, 0, 1)
        create_enemy(ene, gfx, data, 10, 448, 146, 338, 448, 0, 0, 1, 1, 1, 0, 0, 2, 0, 1)
        create_switch(switch, 162 + sx, 148 + sy, 4, 4, 2)
        create_switch(switch, 94 + sx, 148 + sy, 4, 4, 3)
        set_background_image(world, 1)
        return
    end

    if room == 6 then
        create_enemy(ene, gfx, data, 20, 8, 196, 8, 190, 100, 100, 0, 0, 1, 1, 0, 8, 0, 1)
        create_enemy(ene, gfx, data, 20, 230, 160, 230, 428, 236, 236, 0, 0, 1, 1, 0, 8, 0, 1)
        set_background_image(world, 1)
        return
    end

    if room == 8 then
        create_enemy(ene, gfx, data, 8, 96, 224, 96, 400, 100, 100, 0, 0, 1, 1, 0, 16, 0, 1)
        create_enemy(ene, gfx, data, 36, 64, 64, 144, 400, 64, 192, 0, 0, 1, 0, 0, 0, 4, 1)
        create_enemy(ene, gfx, data, 36, 272, 32, 272, 400, 32, 176, 0, 0, 1, 0, 0, 0, 8, 1)
        create_enemy(ene, gfx, data, 2, 128, 80, 128, 224, 100, 100, 0, 0, 2, 1, 0, 2, 0, 1)
        create_switch(switch, 416, 32, 4, 4, 4)
        set_background_image(world, 7)
        return
    end

    if room == 9 then
        create_enemy(ene, gfx, data, 6, 256, 128, 256, 400, 144, 144, 0, 0, 1, 0, 0, 8, 0, 1)
        create_enemy(ene, gfx, data, 6, 144, 96, 144, 400, 32, 96, 0, 0, 1, 0, 0, 0, 2, 1)
        create_enemy(ene, gfx, data, 36, 64, 176, 64, 160, -1, -1, 0, 0, 1, 0, 0, 4, 0, 1)
        create_enemy(ene, gfx, data, 36, 272, 176, 272, 344, -1, -1, 0, 0, 1, 0, 0, 8, 0, 1)
        create_switch(switch, 416, 176, 4, 4, 5)
        create_switch(switch, 192, 144, 4, 4, 6)
        create_energy(energy, 432, 48, 2)
        create_platform(plat, 2, 320, 64, 4, 0, 320, 384, 384, 80, 0, 1)
        set_background_image(world, 7)
        return
    end

    if room == 10 then
        create_switch(switch, 224, 32, 4, 4, 7)
        create_switch(switch, 128, 32, 4, 4, 8)
        create_enemy(ene, gfx, data, 41, 92, 192, 92, 280, 0, 0, 0, 0, 1, 0, 0, 8, 0, 1)
        create_enemy(ene, gfx, data, 2, 320, 32, 0, 0, 32, 112, 0, 0, 2, 0, 0, 0, 2, 1)
        create_enemy(ene, gfx, data, 41, 224, 48, 0, 0, 48, 112, 0, 0, 2, 0, 0, 0, 2, 1)
        create_enemy(ene, gfx, data, 2, 128, 48, 0, 0, 48, 112, 0, 0, 2, 0, 0, 0, 2, 1)
        create_enemy(ene, gfx, data, 2, 416, 224, 0, 0, 112, 224, 0, 0, 1, 0, 0, 0, 4, 1)
        set_background_image(world, 7)
        return
    end

    if room == 11 then
        create_enemy(ene, gfx, data, 17, 192, 96, 40, 0, 96, 192, 0, 0, 1, 0, 1, 0, 4, 1)
        create_enemy(ene, gfx, data, 18, 256, 144, 0, 0, 96, 192, 0, 0, 1, 0, 1, 0, 6, 1)
        create_enemy(ene, gfx, data, 17, 320, 192, 0, 0, 96, 192, 0, 0, 1, 0, 1, 0, 8, 1)
        create_platform(plat, 1, 80, 80, 4, 0, 72, 80, 128, 80, 0, 1)
        create_platform(plat, 2, 216, 80, 4, 0, 192, 320, 320, 80, 0, 1)
        create_switch(switch, 32, 32, 4, 4, 9)
        create_energy(energy, 432, 240, 3)
        set_background_image(world, 7)
    end

    if room == 12 then
        create_platform(plat, 1, 416, 144, 0, 8, 64, 64, 64, 208, 1, 0)
        create_switch(switch, 32, 32, 4, 4, 10)
        set_background_image(world, 7)
    end

    if room == 13 then
        create_enemy(ene, gfx, data, 4, 184, 224, 184, 280, 144, 144, 0, 0, 1, 0, 0, 8, 0, 1)
        create_enemy(ene, gfx, data, 5, 176, 96, 176, 336, 144, 144, 0, 0, 2, 0, 0, 4, 0, 1)
        create_enemy(ene, gfx, data, 5, 208, 176, 208, 368, 144, 144, 0, 0, 1, 0, 0, 8, 0, 1)
        create_enemy(ene, gfx, data, 4, 144, 192, 144, 280, 32, 192, 0, 0, 2, 0, 0, 0, 4, 1)
        set_background_image(world, 7)
    end

    if room == 14 then
        create_enemy(ene, gfx, data, 20, 52, 164, 52, 248, 236, 236, 0, 0, 1, 1, 0, 4, 0, 1)
        create_enemy(ene, gfx, data, 16, 324, 76, 416, 416, 16, 172, 0, 0, 1, 0, 1, 0, 16, 1)
        create_energy(energy, 32, 16, 4)
        create_energy(energy, 32, 160, 5)
        create_platform(plat, 0, 192, 192, 16, 0, 192, 0, 368, 0, 0, 1)
        set_background_image(world, 1)
        return
    end

    if room == 15 then
        create_enemy(ene, gfx, data, 20, 96, 168, 96, 224, -1, -1, 0, 0, 1, 1, 0, 4, 0, 1)
        create_enemy(ene, gfx, data, 20, 144, 64, 144, 416, -1, -1, 0, 0, 1, 1, 0, 24, 0, 1)
        create_enemy(ene, gfx, data, 16, 80, 76, -1, -1, 0, 112, 0, 0, 1, 0, 1, 0, 16, 1)
        return
    end

    if room == 16 then
        create_platform(plat, 2, 32, 64, 0, 4, 0, 64, 0, 144, 1, 1)
        create_platform(plat, 1, 384, 72, 0, 4, 0, 72, 0, 144, 1, 1)
        create_enemy(ene, gfx, data, 8, 32, 160, 32, 96, 0, 0, 0, 0, 1, 1, 0, 4, 0, 1)
        create_enemy(ene, gfx, data, 2, 96, 224, 96, 160, 0, 0, 0, 0, 1, 1, 0, 5, 0, 1)
        create_enemy(ene, gfx, data, 7, 288, 224, 288, 400, 0, 0, 0, 0, 1, 1, 0, 5, 0, 1)
        create_platform(plat, 2, 176, 80, 4, 0, 176, 0, 256, 0, 0, 1)
        set_background_image(world, 2)
    end

    if room == 17 then
        create_energy(energy, 112, 160, 6)
        create_energy(energy, 80, 160, 7)
        create_enemy(ene, gfx, data, 17, 288, 96, 0, 0, 96, 192, 2, 0, 1, 0, 1, 0, 3, 1)
        create_enemy(ene, gfx, data, 2, 336, 128, 336, 416, 0, 0, 0, 0, 1, 1, 0, 3, 0, 1)
        create_enemy(ene, gfx, data, 41, 40, 224, 40, 240, 0, 0, 0, 0, 2, 1, 0, 8, 0, 4)
        create_platform(plat, 2, 32, 152, 0, 4, 0, 72, 0, 152, 1, 1)
        set_background_image(world, 2)
        return
    end

    if room == 18 then
        create_enemy(ene, gfx, data, 36, 416, 76, -1, -1, 40, 192, 0, 0, 2, 0, 1, 0, 8, 1)
        create_enemy(ene, gfx, data, 6, 48, 224, -1, -1, 112, 224, 0, 0, 2, 0, 1, 0, 4, 1)
        create_enemy(ene, gfx, data, 8, 320, 32, 176, 320, -1, -1, 0, 0, 1, 1, 0, 6, 0, 1)
        create_enemy(ene, gfx, data, 7, 32, 48, 32, 120, -1, -1, 0, 0, 1, 1, 0, 4, 0, 1)
        create_energy(energy, 16, 160, 8)
        create_switch(switch, 366, 32, 4, 4, 11)
        create_platform(plat, 1, 368, 80, 0, 4, 368, 80, 168, 200, 1, 0)
        set_background_image(world, 2)
        return
    end

    if room == 19 then
        create_enemy(ene, gfx, data, 27, 352, 76, -1, -1, 56, 144, 0, 0, 1, 0, 1, 0, 6, 1)
        create_enemy(ene, gfx, data, 38, 208, 48, 192, 320, 320, 320, 0, 0, 1, 1, 0, 2, 0, 1)
        create_enemy(ene, gfx, data, 2, 80, 144, 72, 336, 360, 360, 0, 0, 1, 1, 0, 16, 0, 1)
        create_platform(plat, 1, 96, 96, 4, 0, 96, 80, 168, 80, 0, 1)
        create_switch(switch, 128, 32, 4, 4, 12)
        create_energy(energy, 32, 208, 9)
        set_background_image(world, 2)
        return
    end

    if room == 20 then
        create_platform(plat, 1, 352, 144, 0, 8, 64, 144, 64, 232, 1, 0)
        create_platform(plat, 2, 416, 64, 0, 4, 48, 40, 64, 104, 1, 0)
        set_background_image(world, 2)
    end

    if room == 21 then
        create_enemy(ene, gfx, data, 16, 414, 76, -1, -1, 32, 128, 0, 0, 1, 0, 1, 0, 6, 1)
        create_platform(plat, 1, 64, 136, 0, 8, 64, 88, 64, 170, 1, 0)
        create_platform(plat, 2, 312, 80, 8, 0, 192, 80, 312, 80, 0, 1)
        create_switch(switch, 64, 32, 4, 4, 13)
        create_energy(energy, 32, 240, 10)
        set_background_image(world, 2)
        return
    end

    if room == 22 then
        create_platform(plat, 0, 264, 136, 0, 4, 64, 96, 64, 208, 1, 0)
        create_platform(plat, 0, 32, 88, 4, 0, 32, 88, 160, 88, 0, 1)
        create_platform(plat, 0, 48, 160, 4, 0, 32, 144, 176, 144, 0, 1)
        create_switch(switch, 32, 32, 4, 4, 14)
        set_background_image(world, 1)
        return
    end

    if room == 23 then
        create_enemy(ene, gfx, data, 20, 48, 112, 48, 208, -1, -1, 0, 0, 1, 1, 0, 8, 0, 1)
        create_energy(energy, 144, 192, 11)
        create_energy(energy, 160, 192, 12)
        set_background_image(world, 1)
        return
    end

    if room == 24 then
        create_enemy(ene, gfx, data, 6, 256, 96, 0, 0, 32, 128, 0, 0, 1, 1, 0, 0, 4, 0)
        create_enemy(ene, gfx, data, 44, 144, 224, 144, 352, -1, -1, 0, 0, 1, 1, 0, 8, 0, 1)
        create_energy(energy, 64, 144, 13)
        create_platform(plat, 1, 208, 160, 4, 0, 208, 160, 288, 160, 0, 1)
        set_background_image(world, 7)
        return
    end

    if room == 25 then
        create_enemy(ene, gfx, data, 17, 224, 96, 224, 224, 32, 96, 0, 0, 1, 1, 0, 0, 2, 0)
        create_switch(switch, 320, 32, 4, 4, 15)
        create_energy(energy, 432, 64, 14)
        create_platform(plat, 2, 320, 72, 0, 8, 320, 72, 420, 128, 1, 0)
        create_platform(plat, 1, 48, 112, 8, 0, 48, 112, 192, 112, 0, 1)
        create_platform(plat, 2, 32, 160, 8, 0, 32, 160, 224, 160, 0, 1)
        set_background_image(world, 7)
        return
    end

    if room == 26 then
        create_enemy(ene, gfx, data, 13, 320, 224, 96, 320, -1, -1, 0, 0, 1, 1, 0, 8, 0, 1)
        create_enemy(ene, gfx, data, 2, 96, 90, 0, 0, 88, 160, 0, 0, 1, 0, 0, 0, 8, 0)
        create_switch(switch, 32, 32, 4, 4, 16)
        create_switch(switch, 416, 32, 4, 4, 17)
        set_background_image(world, 7)
        return
    end

    if room == 27 then
        create_enemy(ene, gfx, data, 4, 168, 224, 168, 304, 144, 144, 0, 0, 1, 0, 0, 6, 0, 1)
        create_switch(switch, 416, 192, 4, 4, 18)
        create_switch(switch, 416, 80, 4, 4, 19)
        create_platform(plat, 2, 32, 56, 0, 8, 32, 64, 416, 232, 1, 0)
        create_platform(plat, 2, 144, 120, 0, 8, 144, 80, 416, 216, 1, 0)
        create_energy(energy, 112, 112, 15)
        create_energy(energy, 112, 160, 16)
        set_background_image(world, 7)
        return
    end

    if room == 28 then
        create_platform(plat, 1, 216, 48, 8, 0, 216, 0, 384, 0, 0, 1)
        create_platform(plat, 2, 32, 104, 0, 8, 32, 32, 416, 168, 1, 0)
        create_enemy(ene, gfx, data, 2, 192, 144, 192, 224, 0, 0, 0, 0, 1, 0, 0, 2, 0, 1)
        set_background_image(world, 7)
        return
    end

    if room == 29 then
        create_enemy(ene, gfx, data, 2, 144, 80, 104, 344, -1, -1, 0, 0, 1, 1, 0, 12, 0, 1)
        create_platform(plat, 1, 280, 192, 4, 0, 280, 0, 416, 0, 0, 1)
        create_platform(plat, 2, 164, 192, 4, 0, 164, 0, 240, 0, 0, 1)
        create_platform(plat, 1, 32, 192, 8, 0, 32, 0, 96, 0, 0, 1)
        create_platform(plat, 2, 416, 104, 0, 4, 416, 32, 416, 104, 1, 0)
        create_switch(switch, 32, 32, 4, 4, 20)
        set_background_image(world, 7)
        return
    end

    if room == 30 then
        create_enemy(ene, gfx, data, 16, 32, 16, -1, -1, 16, 128, 0, 0, 1, 0, 1, 0, 8, 1)
        create_enemy(ene, gfx, data, 16, 128, 72, -1, -1, 16, 128, 0, 0, 1, 0, 1, 0, 8, 1)
        create_enemy(ene, gfx, data, 20, 176, 168, 112, 328, 236, 236, 0, 0, 1, 1, 0, 10, 0, 1)
        create_enemy(ene, gfx, data, 13, 368, 224, 288, 416, -1, -1, 0, 0, 1, 1, 0, 6, 0, 1)
        set_background_image(world, 1)
        return
    end

    if room == 31 then
        set_background_image(world, 1)
        return
    end

    if room == 32 then
        create_enemy(ene, gfx, data, 13, 112, 224, 112, 320, -1, -1, 0, 0, 2, 1, 0, 4, 0, 1)
        create_enemy(ene, gfx, data, 39, 288, 128, 288, 340, -1, -1, 0, 0, 2, 1, 0, 4, 0, 1)
        create_enemy(ene, gfx, data, 40, 64, 160, 0, 0, 96, 160, 0, 0, 1, 0, 1, 0, 6, 1)
        create_switch(switch, 96, 112, 4, 4, 21)
        create_switch(switch, 336, 80, 4, 4, 22)
        set_background_image(world, 2)
        return
    end

    if room == 33 then
        create_enemy(ene, gfx, data, 39, 320, 128, 0, 0, 48, 128, 0, 0, 1, 0, 1, 0, 3, 1)
        create_enemy(ene, gfx, data, 1, 272, 80, 0, 0, 80, 176, 0, 0, 1, 0, 1, 0, 2, 1)
        create_enemy(ene, gfx, data, 40, 160, 144, 0, 0, 32, 144, 0, 0, 1, 0, 1, 0, 6, 1)
        create_enemy(ene, gfx, data, 13, 32, 224, 32, 240, -1, -1, 0, 0, 1, 1, 0, 6, 0, 1)
        create_platform(plat, 1, 32, 176, 4, 0, 32, 80, 128, 80, 0, 1)
        set_background_image(world, 2)
        return
    end

    if room == 34 then
        create_enemy(ene, gfx, data, 40, 64, 136, 0, 0, 112, 192, 0, 0, 1, 0, 1, 0, 4, 1)
        create_enemy(ene, gfx, data, 40, 384, 192, 0, 0, 112, 192, 0, 0, 1, 0, 1, 0, 4, 1)
        create_enemy(ene, gfx, data, 39, 176, 144, 176, 240, 0, 0, 0, 0, 1, 1, 8, 12, 0, 1)
        create_platform(plat, 2, 32, 80, 4, 0, 32, 80, 416, 80, 0, 1)
        create_switch(switch, 32, 144, 4, 4, 23)
        create_switch(switch, 416, 144, 4, 4, 24)
        set_background_image(world, 2)
        return
    end

    if room == 35 then
        create_switch(switch, 128, 224, 4, 4, 25)
        create_energy(energy, 320, 208, 17)
        set_background_image(world, 2)
        return
    end

    if room == 36 then
        create_enemy(ene, gfx, data, 1, 32, 80, -1, -1, 80, 224, 0, 0, 1, 0, 1, 0, 4, 1)
        create_enemy(ene, gfx, data, 39, 128, 80, -1, -1, 32, 144, 0, 0, 1, 0, 1, 0, 4, 1)
        create_enemy(ene, gfx, data, 40, 248, 224, 248, 408, 108, 220, 0, 0, 1, 0, 1, 7, 0, 1)
        create_enemy(ene, gfx, data, 31, 64, 224, 64, 144, -1, -1, 0, 0, 2, 1, 0, 4, 0, 1)
        create_switch(switch, 240, 32, 4, 4, 26)
        create_switch(switch, 176, 32, 4, 4, 27)
        set_background_image(world, 2)
        return
    end

    if room == 37 then
        create_enemy(ene, gfx, data, 1, 64, 80, -1, -1, 80, 160, 0, 0, 1, 0, 1, 0, 4, 1)
        create_enemy(ene, gfx, data, 39, 96, 80, -1, -1, 80, 160, 0, 0, 1, 0, 1, 0, 2, 1)
        create_enemy(ene, gfx, data, 40, 128, 80, -1, -1, 80, 160, 0, 0, 1, 0, 1, 0, 6, 1)
        create_enemy(ene, gfx, data, 39, 104, 224, 104, 336, 108, 220, 0, 0, 1, 0, 1, 4, 0, 1)
        create_energy(energy, 32, 224, 18)
        create_energy(energy, 48, 224, 19)
        create_energy(energy, 32, 240, 20)
        create_energy(energy, 48, 240, 21)
        create_energy(energy, 384, 32, 22)
        create_energy(energy, 368, 32, 23)
        create_energy(energy, 432, 128, 24)
        create_platform(plat, 1, 224, 72, 0, 4, 32, 72, 416, 208, 1, 0)
        create_platform(plat, 2, 276, 128, 4, 0, 276, 0, 400, 0, 0, 1)
        set_background_image(world, 2)
        return
    end

    if room == 38 then
        create_platform(plat, 1, 96, 80, 4, 0, 96, 0, 208, 0, 0, 1)
        create_platform(plat, 1, 208, 112, 4, 0, 208, 0, 336, 0, 0, 1)
        create_enemy(ene, gfx, data, 40, 64, 96, 288, 288, 32, 192, 0, 0, 1, 1, 1, 0, 9, 0)
        create_enemy(ene, gfx, data, 1, 144, 224, 352, 208, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        create_switch(switch, 416, 32, 4, 4, 28)
        create_switch(switch, 32, 32, 4, 4, 29)
        set_background_image(world, 2)
        return
    end

    if room == 39 then
        create_enemy(ene, gfx, data, 40, 128, 160, 128, 416, 0, 0, 0, 0, 1, 1, 0, 10, 0, 1)
        create_enemy(ene, gfx, data, 39, 64, 64, 64, 234, 0, 0, 0, 0, 1, 1, 0, 6, 0, 1)
        create_enemy(ene, gfx, data, 39, 272, 80, 272, 416, 0, 0, 0, 0, 1, 1, 0, 4, 0, 1)
        create_switch(switch, 416, 32, 4, 4, 30)
        create_switch(switch, 32, 32, 4, 4, 31)
        set_background_image(world, 2)
        return
    end

    if room == 40 then
        create_switch(switch, 320, 32, 4, 4, 32)
        create_energy(energy, 32, 176, 25)
        create_energy(energy, 240, 96, 26)
        create_energy(energy, 272, 64, 27)
        create_energy(energy, 400, 160, 28)
        create_enemy(ene, gfx, data, 22, 32, 112, 32, 176, 0, 0, 0, 0, 1, 1, 0, 2, 0, 2)
        create_enemy(ene, gfx, data, 22, 32, 224, 32, 248, 0, 0, 0, 0, 1, 1, 0, 6, 0, 2)
        create_enemy(ene, gfx, data, 22, 296, 96, 296, 385, 0, 0, 0, 0, 1, 1, 0, 2, 0, 1)
        set_background_image(world, 8)
        return
    end

    if room == 41 then
        create_enemy(ene, gfx, data, 1, 80, 32, 80, 208, 32, 160, 0, 0, 1, 1, 4, 0, 4, 4)
        create_enemy(ene, gfx, data, 40, 384, 96, 288, 384, 0, 0, 0, 0, 1, 1, 0, 4, 0, 0)
        create_enemy(ene, gfx, data, 1, 256, 224, 256, 432, 0, 0, 0, 0, 1, 1, 0, 8, 0, 0)
        create_enemy(ene, gfx, data, 11, 224, 208, 336, 336, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0)
        create_energy(energy, 32, 32, 29)
        create_energy(energy, 432, 32, 30)
        create_platform(plat, 2, 160, 128, 4, 0, 160, 72, 256, 208, 0, 1)
        set_background_image(world, 8)
        return
    end

    if room == 42 then
        create_enemy(ene, gfx, data, 22, 208, 80, 0, 0, 80, 224, 0, 0, 2, 1, 8, 0, 8, 4)
        create_enemy(ene, gfx, data, 11, 96, 208, 64, 208, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        create_enemy(ene, gfx, data, 11, 176, 208, 176, 176, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        create_enemy(ene, gfx, data, 11, 256, 208, 256, 256, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        create_enemy(ene, gfx, data, 11, 336, 208, 336, 336, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        create_energy(energy, 32, 128, 31)
        create_energy(energy, 432, 128, 32)
        set_background_image(world, 8)
        return
    end

    if room == 43 then
        create_enemy(ene, gfx, data, 22, 64, 64, 80, 400, 224, 300, 0, 0, 2, 1, 0, 16, 0, 4)
        create_enemy(ene, gfx, data, 39, 320, 224, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1)
        create_enemy(ene, gfx, data, 39, 288, 224, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 2)
        create_platform(plat, 1, 336, 96, 4, 0, 336, 416, 416, 208, 0, 1)
        create_energy(energy, 112, 32, 33)
        set_background_image(world, 8)
        return
    end

    if room == 44 then
        create_enemy(ene, gfx, data, 22, 32, 32, 32, 416, 224, 300, 0, 0, 2, 1, 0, 6, 0, 4)
        create_enemy(ene, gfx, data, 40, 320, 224, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1)
        create_enemy(ene, gfx, data, 1, 288, 224, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 2)
        set_background_image(world, 8)
        return
    end

    if room == 45 then
        create_enemy(ene, gfx, data, 11, 48, 208, 48, 208, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        create_enemy(ene, gfx, data, 22, 64, 160, 64, 220, 300, 300, 0, 0, 1, 1, 0, 4, 0, 1)
        create_enemy(ene, gfx, data, 22, 128, 224, 128, 240, 224, 300, 0, 0, 2, 1, 0, 2, 0, 2)
        create_energy(energy, 272, 160, 34)
        create_energy(energy, 304, 160, 35)
        create_energy(energy, 432, 48, 36)
        create_energy(energy, 240, 112, 37)
        create_platform(plat, 1, 32, 80, 0, 4, 32, 80, 416, 192, 1, 0)
        set_background_image(world, 8)
        return
    end

    if room == 46 then
        create_enemy(ene, gfx, data, 39, 272, 224, 272, 416, 0, 0, 0, 0, 2, 1, 0, 4, 0, 1)
        create_enemy(ene, gfx, data, 40, 32, 80, 0, 0, 80, 160, 0, 0, 1, 1, 1, 0, 4, 0)
        create_enemy(ene, gfx, data, 1, 144, 32, 0, 0, 32, 176, 0, 0, 1, 1, 1, 0, 6, 0)
        create_enemy(ene, gfx, data, 22, 272, 32, 0, 0, 32, 176, 0, 0, 1, 1, 1, 0, 6, 0)
        create_enemy(ene, gfx, data, 11, 240, 208, 352, 208, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        set_background_image(world, 8)
        return
    end

    if room == 47 then
        create_energy(energy, 192, 32, 38)
        create_enemy(ene, gfx, data, 22, 32, 80, 32, 272, 0, 0, 0, 0, 1, 1, 0, 6, 0, 1)
        create_enemy(ene, gfx, data, 22, 32, 144, 32, 224, 0, 0, 0, 0, 2, 1, 0, 3, 0, 1)
        create_enemy(ene, gfx, data, 11, 240, 208, 352, 208, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        create_enemy(ene, gfx, data, 11, 64, 208, 352, 208, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        set_background_image(world, 8)
        return
    end

    if room == 48 then
        create_energy(energy, 32, 224, 39)
        create_energy(energy, 32, 240, 40)
        create_enemy(ene, gfx, data, 22, 144, 176, 144, 400, 0, 0, 0, 0, 1, 1, 0, 6, 0, 1)
        create_enemy(ene, gfx, data, 1, 64, 32, 0, 0, 32, 224, 0, 0, 1, 1, 1, 0, 6, 0)
        create_enemy(ene, gfx, data, 22, 256, 32, 288, 288, 32, 128, 0, 0, 2, 1, 1, 0, 6, 0)
        create_enemy(ene, gfx, data, 11, 384, 208, 352, 208, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        create_enemy(ene, gfx, data, 11, 272, 208, 352, 208, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        set_background_image(world, 4)
        return
    end

    if room == 49 then
        create_enemy(ene, gfx, data, 11, 80, 208, 48, 208, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        create_enemy(ene, gfx, data, 11, 176, 208, 48, 208, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        create_enemy(ene, gfx, data, 11, 272, 208, 48, 208, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        create_enemy(ene, gfx, data, 11, 368, 208, 48, 208, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        set_background_image(world, 4)
        return
    end

    if room == 50 then
        create_enemy(ene, gfx, data, 23, 120, 192, 48, 208, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        create_enemy(ene, gfx, data, 23, 312, 192, 48, 208, 284, 284, 0, 0, 2, 1, 1, 0, 0, 0)
        create_platform(plat, 1, 80, 160, 4, 0, 80, 160, 128, 160, 0, 1)
        create_platform(plat, 1, 272, 160, 4, 0, 272, 160, 352, 160, 0, 1)
        set_background_image(world, 4)
        return
    end

    if room == 51 then
        create_energy(energy, 432, 32, 41)
        create_energy(energy, 432, 48, 42)
        create_platform(plat, 1, 208, 80, 4, 0, 208, 0, 352, 0, 0, 1)
        create_enemy(ene, gfx, data, 40, 80, 224, 80, 256, 0, 0, 0, 0, 1, 1, 0, 4, 0, 1)
        create_enemy(ene, gfx, data, 22, 0, 112, 0, 208, 0, 0, 0, 0, 1, 1, 0, 8, 0, 1)
        create_enemy(ene, gfx, data, 22, 288, 96, 0, 0, 96, 224, 0, 0, 1, 1, 1, 0, 2, 0)
        create_enemy(ene, gfx, data, 11, 352, 208, 352, 208, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        set_background_image(world, 4)
        return
    end

    if room == 52 then
        create_enemy(ene, gfx, data, 22, 208, 128, 208, 368, 0, 0, 0, 0, 1, 1, 0, 6, 0, 1)
        create_enemy(ene, gfx, data, 22, 32, 128, 0, 0, 0, 128, 0, 0, 1, 1, 1, 0, 8, 0)
        create_enemy(ene, gfx, data, 1, 240, 224, 240, 416, 0, 0, 0, 0, 1, 1, 0, 16, 0, 1)
        create_energy(energy, 416, 112, 43)
        create_energy(energy, 432, 112, 44)
        create_energy(energy, 416, 128, 45)
        create_energy(energy, 432, 128, 46)
        create_energy(energy, 416, 144, 47)
        create_energy(energy, 432, 144, 48)
        set_background_image(world, 4)
        return
    end

    if room == 53 then
        create_enemy(ene, gfx, data, 22, 96, 224, 0, 0, 80, 224, 0, 0, 1, 1, 1, 0, 10, 0)
        create_enemy(ene, gfx, data, 1, 160, 224, 160, 352, 0, 0, 0, 0, 1, 1, 0, 4, 0, 1)
        create_enemy(ene, gfx, data, 11, 384, 208, 336, 336, 284, 284, 0, 0, 1, 1, 1, 0, 0, 0)
        create_energy(energy, 432, 176, 49)
        create_platform(plat, 2, 32, 80, 0, 4, 32, 80, 416, 240, 1, 0)
        set_background_image(world, 4)
        return
    end

    if room == 54 then
        create_enemy(ene, gfx, data, 32, 96, 96, 32, 336, 80, 224, 0, 0, 2, 1, 1, 8, 0, 1)
        create_enemy(ene, gfx, data, 39, 352, 224, 64, 352, 128, 128, 0, 0, 1, 1, 0, 6, 0, 1)
        create_enemy(ene, gfx, data, 12, 400, 192, 336, 336, 144, 192, 0, 0, 1, 0, 1, 0, 2, 0)
        create_platform(plat, 1, 32, 152, 0, 4, 32, 152, 416, 208, 1, 0)
        create_switch(switch, 416, 32, 4, 4, 33)
        create_platform(plat, 2, 272, 128, 4, 0, 272, 0, 384, 0, 0, 1)
        create_platform(plat, 2, 32, 128, 4, 0, 32, 0, 96, 0, 0, 1)
        create_platform(plat, 1, 96 + 64, 128, 4, 0, 96 + 32, 0, 272 - 32, 0, 0, 1)
        set_background_image(world, 4)
        return
    end

    if room == 55 then
        create_enemy(ene, gfx, data, 39, 48, 80, 288, 288, 80, 144, 0, 0, 1, 1, 1, 0, 2, 0)
        create_enemy(ene, gfx, data, 40, 128, 80, 288, 288, 80, 224, 0, 0, 1, 1, 1, 0, 8, 0)
        create_enemy(ene, gfx, data, 22, 160, 112, 288, 288, 32, 224, 0, 0, 1, 1, 1, 0, 6, 0)
        create_enemy(ene, gfx, data, 22, 208, 80, 288, 288, 80, 224, 0, 0, 1, 1, 1, 0, 6, 0)
        create_energy(energy, 416, 96, 50)
        create_energy(energy, 432, 96, 51)
        create_energy(energy, 416, 112, 52)
        create_energy(energy, 432, 112, 53)
        set_background_image(world, 4)

        return
    end

    if room == 56 then
        create_platform(plat, 4, 240, 72, 0, 8, 240, 72, 416, 208, 1, 0)
        set_background_image(world, 3)
    end

    if room == 57 then
        set_background_image(world, 5)
    end

    if room == 58 then
        create_enemy(ene, gfx, data, 22, 48, 80, 48, 368, 0, 0, 0, 0, 1, 1, 0, 10, 0, 1)
        create_platform(plat, 4, 272, 112, 4, 0, 272, 0, 400, 0, 0, 2)
        create_platform(plat, 4, 80, 112, 4, 0, 80, 0, 224, 0, 0, 2)
        set_background_image(world, 3)
        return
    end

    if room == 59 then
        create_energy(energy, 432, 112, 54)
        create_energy(energy, 224, 144, 55)
        create_energy(energy, 432, 240, 56)
        create_energy(energy, 32, 240, 57)
        create_energy(energy, 160, 160, 58)
        create_enemy(ene, gfx, data, 22, 80, 112, 80, 288, 32, 224, 0, 0, 1, 1, 1, 0, 6, 0)
        create_enemy(ene, gfx, data, 1, 144, 224, 144, 344, 128, 128, 0, 0, 1, 1, 0, 8, 0, 1)
        set_background_image(world, 5)
        return
    end

    if room == 60 then
        create_platform(plat, 4, 112, 160, 8, 0, 112, 0, 240, 0, 0, 4)
        set_background_image(world, 3)
        return
    end

    if room == 61 then
        create_enemy(ene, gfx, data, 22, 304, 80, 288, 288, 80, 192, 0, 0, 1, 1, 1, 0, 4, 0)
        create_enemy(ene, gfx, data, 22, 80, 32, 288, 288, 32, 224, 0, 0, 1, 1, 1, 0, 6, 0)
        create_enemy(ene, gfx, data, 39, 48, 224, 48, 144, 128, 128, 0, 0, 1, 1, 0, 3, 0, 1)
        create_enemy(ene, gfx, data, 1, 304, 224, 304, 384, 128, 128, 0, 0, 1, 1, 0, 3, 0, 1)
        create_energy(energy, 224, 208, 59)
        create_energy(energy, 240, 208, 60)
        set_background_image(world, 5)
        return
    end

    if room == 62 then
        create_enemy(ene, gfx, data, 22, 352, 80, 288, 288, 80, 192, 0, 0, 1, 1, 1, 0, 4, 0)
        create_enemy(ene, gfx, data, 22, 80, 32, 288, 288, 32, 224, 0, 0, 1, 1, 1, 0, 6, 0)
        create_enemy(ene, gfx, data, 19, 120, 224, 120, 208, 128, 128, 0, 0, 3, 1, 0, 6, 0, 1)
        create_enemy(ene, gfx, data, 19, 256, 224, 256, 368, 128, 128, 0, 0, 1, 1, 0, 8, 0, 1)
        set_background_image(world, 3)
        return
    end

    if room == 63 then
        create_enemy(ene, gfx, data, 40, 384, 32, 0, 0, 32, 192, 0, 0, 1, 1, 1, 0, 4, 0)
        create_enemy(ene, gfx, data, 39, 32, 224, 32, 416, 0, 0, 0, 0, 1, 1, 0, 16, 0, 1)
        create_enemy(ene, gfx, data, 22, 112, 128, 112, 288, 0, 0, 0, 0, 1, 1, 0, 8, 0, 1)
        create_enemy(ene, gfx, data, 22, 64, 32, 64, 328, 0, 0, 0, 0, 1, 1, 0, 8, 0, 1)
        set_background_image(world, 5)
        return
    end

    if room == 64 then
        create_switch(switch, 96, 176, 4, 4, 34)
        set_background_image(world, 6)
    end

    if room == 65 then
        set_background_image(world, 6)
    end

    if room == 66 then
        create_switch(switch, 416, 160, 4, 4, 35)
        set_background_image(world, 0)
    end

    if room == 67 then
        set_background_image(world, 9)
    end
end