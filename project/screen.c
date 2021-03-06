#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "shape.h"

const AbRect rect10 = {abRectGetBounds, abRectCheck, 20, 20};;
const AbRArrow arrow30 = {abRArrowGetBounds, abRArrowCheck, 40};;

void
abDrawPos(AbShape *shape, Vec2 *shapeCenter, u_int fg_color, u_int bg_color)
{
  u_char row, col;
  Region bounds;
  abShapeGetBounds(shape, shapeCenter, &bounds);
  lcd_setArea(bounds.topLeft.axes[0], bounds.topLeft.axes[1],
	      bounds.botRight.axes[0]-1, bounds.botRight.axes[1]-1);
  for (row = bounds.topLeft.axes[1]; row < bounds.botRight.axes[1]; row++) {
    for (col = bounds.topLeft.axes[0]; col < bounds.botRight.axes[0]; col++) {
      Vec2 pixelPos = {col, row};
      int color = abShapeCheck(shape, shapeCenter, &pixelPos) ?
	fg_color : bg_color;
      lcd_writeColor(color);
    }
  }
}

void
drawState1()
{
  Vec2 rectPos = screenCenter;

  clearScreen(COLOR_BLUE);
  drawString5x7(20, 40, "STATE_ONE", COLOR_ORANGE, COLOR_BLUE);
  shapeInit();
  abDrawPos((AbShape*)&arrow30, &rectPos, COLOR_ORANGE, COLOR_BLUE);
}

void
drawState2()
{
  Vec2 rectPos = screenCenter;

  clearScreen(COLOR_RED);
  drawString5x7(30, 40, "STATE_TWO", COLOR_YELLOW, COLOR_RED);
  shapeInit();
  abDrawPos((AbShape*)&rect10, &rectPos, COLOR_YELLOW, COLOR_RED);
}

//int
//main()
//{
  //configureClocks();
  //lcd_init();
  //shapeInit();
  //drawState1();
  //Vec2 rectPos = screenCenter;

  //clearScreen(COLOR_MAGENTA);
  //drawString5x7(20, 40, "Sergio", COLOR_CYAN, COLOR_MAGENTA);
  //shapeInit();

  //abDrawPos((AbShape*)&arrow30, &rectPos, COLOR_CYAN, COLOR_MAGENTA);
  //abDrawPos((AbShape*)&rect10, &rectPos, COLOR_CYAN, COLOR_MAGENTA);
  //}
