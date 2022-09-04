#include "ppcd.h"

int sn_collision(BITMAP *s1, int s1x1, int s1y1, BITMAP *s2, int s2x1, int s2y1) {
    int mask = bitmap_mask_color(s1);
    int mask2 = bitmap_mask_color(s2);
    int s1x2 = s1x1 + (s1->w * 2) - 1;
    int s1y2 = s1y1 + (s1->h * 2) - 1;
    int s2x2 = s2x1 + (s2->w * 2) - 1;
    int s2y2 = s2y1 + (s2->h * 2) - 1;
    int left = s1x1;
    int right = s1x2;
    int top = s1y1;
    int bottom = s1y2;
    int x, y;

    if (s1x1 > s2x2 || s1x2 < s2x1 || s1y1 > s2y2 || s1y2 < s2y1) {
        return FALSE;
    }
    // 	if (gametype==GAME_CLASSIC)
    // 	{
    // 		return TRUE;
    // 	}

    if (s1x1 <= s2x1) left = s2x1;
    if (s1x2 >= s2x2) right = s2x2;
    if (s1y1 <= s2y1) top = s2y1;
    if (s1y2 >= s2y2) bottom = s2y2;

    for (y = top; y <= bottom; y++) {
        for (x = left; x <= right; x++) {
            if ((getpixel(s1, (x - s1x1) / 2, (y / 2 - s1y1) / 2) != mask) &&
                (getpixel(s2, (x - s2x1) / 2, (y - s2y1) / 2) != mask2)) {
                return TRUE;
            }
        }
    }
    return FALSE;
}
