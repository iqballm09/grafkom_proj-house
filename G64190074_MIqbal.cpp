#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

/* Define Colors */
#define gray 232, 232, 232
#define green 150, 172, 2
#define cream 192, 169, 135
#define brown 198, 139, 99
#define oldBrown 150, 98, 74
#define blue 135, 206, 235
#define yellow 246, 241, 117
#define white1 232, 232, 232
#define white2 193, 193, 193
#define black 35, 35, 35

int lampGarden = -1;
int status = -1;

/*Create Classes*/
class Components
{
public:
    void rectangle(double a1, double a2, double b1, double b2)
    {
        glBegin(GL_QUADS);
        glVertex2d(a1, b1);
        glVertex2d(a2, b1);
        glVertex2d(a2, b2);
        glVertex2d(a1, b2);
        glEnd();
    }

    void plane4v(double a1, double a2, double a3, double a4, double b1, double b2, double b3, double b4)
    {
        glBegin(GL_POLYGON);
        glVertex2d(a1, b1);
        glVertex2d(a2, b2);
        glVertex2d(a3, b3);
        glVertex2d(a4, b4);
        glEnd();
    }

    void triangle(double a1, double a2, double a3, double b1, double b2, double b3)
    {
        glBegin(GL_TRIANGLES);
        glVertex2d(a1, b1);
        glVertex2d(a2, b2);
        glVertex2d(a3, b3);
        glEnd();
    }

    void plane5v(double a1, double a2, double a3, double a4, double a5, double b1, double b2, double b3, double b4, double b5)
    {
        glBegin(GL_POLYGON);
        glVertex2d(a1, b1);
        glVertex2d(a2, b2);
        glVertex2d(a3, b3);
        glVertex2d(a4, b4);
        glVertex2d(a5, b5);
        glEnd();
    }
};

class MyHome : public Components
{
public:
    void land()
    {
        glBegin(GL_QUAD_STRIP);
        glColor3ub(180, 180, 180);
        glVertex2d(142.5, 587);
        glVertex2d(142.5, 559);
        glVertex2d(401, 735.5);
        glVertex2d(401, 708.5);
        glVertex2d(658, 587);
        glVertex2d(658, 559);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(gray);
        glVertex2d(222.5, 605);
        glVertex2d(296, 558);
        glVertex2d(330.5, 577.5);
        glVertex2d(302.5, 594);
        glVertex2d(333, 612);
        glVertex2d(412.5, 566);
        glVertex2d(494, 613);
        glVertex2d(494, 618);
        glVertex2d(419, 661);
        glVertex2d(450, 680);
        glVertex2d(401, 708.5);
        glEnd();

        glColor3ub(gray);
        plane4v(142.5, 222.5, 269, 192.5, 558.5, 605, 574.5, 530);
        plane4v(142.5, 192.5, 287.5, 245, 558.5, 530, 585.5, 618);
        plane4v(142.5, 142.5, 401, 401, 558.5, 586, 735.5, 708.5);
    }
    void grass()
    {
        glColor3ub(green);
        plane4v(494, 419, 450, 527, 617.5, 661, 680, 635.5);
        plane4v(506.5, 521, 658, 646, 630, 638.5, 559, 552);
        triangle(633, 653, 633, 567.5, 556, 544.5);

        plane4v(302.5, 333, 379, 347.5, 594, 612, 585.5, 567.5);
        plane4v(363, 375.5, 408.5, 396.5, 580.5, 587.5, 568, 561.5);
        plane4v(269, 311.5, 238, 192.5, 574.5, 547, 504, 530);
        triangle(253, 238, 253, 512.5, 504, 493);
        glColor3ub(green);
        plane4v(457, 457, 658, 658, 676, 682, 564.5, 559);
    }

    void wall()
    {
        /* Lower Side*/
        glColor3ub(cream);
        plane4v(494, 494, 511.5, 511.5, 597.5, 618, 627, 606.5);
        glColor3ub(188, 166, 134);
        plane4v(511.5, 511.5, 633, 633, 606.5, 627, 559.5, 539.5);
        glBegin(GL_QUAD_STRIP);
        glVertex2d(348, 548);
        glVertex2d(348, 567.5);
        glVertex2d(367, 558.5);
        glVertex2d(367, 578);
        glVertex2d(396.5, 541);
        glVertex2d(396.5, 561.5);
        glVertex2d(409, 547.5);
        glVertex2d(409, 568);
        glEnd();
        plane4v(253, 253, 307.5, 307.5, 493.5, 512.5, 545, 524.5);

        /* Upper Side */
        glColor3ub(193, 193, 193);
        plane4v(367, 396.5, 396.5, 367, 396, 428.5, 541, 558.5);
        plane4v(511.5, 511.5, 633, 633, 519.5, 606.5, 539.5, 459.5);

        glColor3ub(gray);
        plane4v(409, 485.5, 485.5, 422.5, 518.5, 561.7, 533, 497);
        glBegin(GL_POLYGON);
        glVertex2d(396.5, 541);
        glVertex2d(396.5, 427.5);
        glVertex2d(422.5, 456.5);
        glVertex2d(422.5, 497);
        glVertex2d(409, 518.5);
        glVertex2d(409, 547);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2d(473.5, 554.7);
        glVertex2d(485.5, 525.5);
        glVertex2d(489.5, 530.5);
        glVertex2d(511.5, 518.5);
        glVertex2d(511.5, 606.5);
        glVertex2d(494, 597);
        glVertex2d(494, 566.5);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(gray);
        glVertex2d(253, 493.5);
        glVertex2d(253, 347);
        glVertex2d(288.5, 309);
        glVertex2d(367, 395.5);
        glVertex2d(367, 558.5);
        glVertex2d(348, 548);
        glVertex2d(348, 479);
        glVertex2d(307, 455.5);
        glVertex2d(307, 524.5);
        glEnd();

        glColor3ub(193, 193, 193);
        plane4v(307.5, 313.5, 313.5, 307.5, 533.5, 530, 459.5, 456);

        glColor3ub(188, 166, 134);
        plane4v(367.5, 367.5, 396.5, 396.5, 558.5, 578, 561.5, 541);
    }

    void door(double R, double G, double B)
    {
        glColor3ub(203, 140, 97);
        plane4v(348, 348, 313.5, 313.5, 548.5, 479, 459, 530);

        glColor3ub(157, 106, 79);
        plane4v(320, 341.5, 341.5, 320, 508, 520.5, 540, 528.5);
        glBegin(GL_QUAD_STRIP);
        glVertex2d(320, 473.5);
        glVertex2d(320, 472);
        glVertex2d(322, 502);
        glVertex2d(320, 504);
        glVertex2d(341.5, 514);
        glVertex2d(341.5, 516);
        glEnd();

        glColor3ub(R, G, B);
        plane4v(322, 341.5, 341.5, 322, 473, 484, 514, 502.5);
        glColor3ub(white1);
        plane5v(335, 341.5, 327.09, 322, 322, 480.33, 484, 505.5, 502.5, 499);
        plane4v(341.5, 341.5, 331.5, 329, 488, 493.5, 508, 506.5);
    }

    void rooftop()
    {
        glColor3ub(brown);
        plane4v(280, 489.5, 651.5, 441, 300, 530, 450, 220.5);
        glColor3ub(oldBrown);
        plane5v(280.5, 233, 252.5, 252.5, 288, 299.5, 357, 353, 347, 309.5);
    }
    void miniRooftop(double R, double G, double B)
    {
        glColor3ub(212, 153, 109);
        plane4v(396, 378.5, 413, 431.5, 261.5, 288, 307.5, 282.5);

        glColor3ub(oldBrown);
        plane4v(396, 431.5, 448.5, 412, 261.5, 282.5, 287, 266);

        glColor3ub(146, 98, 75);
        triangle(378.5, 412, 412, 288, 307, 338.5);

        glColor3ub(oldBrown);
        plane4v(435.5, 429.5, 425, 441, 287, 290, 296.5, 288);
        plane4v(412, 415, 415, 412, 307, 309.5, 340, 338.5);
        plane4v(415.5, 415.5, 441, 441, 337, 340.5, 325.5, 322.5);
        plane4v(441, 441, 438, 438, 288, 325.5, 327.5, 289.5);

        glBegin(GL_QUAD_STRIP);
        glColor3ub(212, 153, 109);
        glVertex2d(413, 307.5);
        glVertex2d(415.5, 309.5);
        glVertex2d(432, 286.5);
        glVertex2d(432, 282.5);
        glVertex2d(448.5, 290);
        glVertex2d(448.5, 287);
        glEnd();

        glColor3ub(R, G, B);
        plane5v(415.5, 415.5, 438, 438, 425, 309.5, 337, 324, 289.5, 296.5);

        glColor3ub(white1);
        glBegin(GL_POLYGON);
        glVertex2d(421.5, 301.5);
        glVertex2d(438, 320);
        glVertex2d(438, 324);
        glVertex2d(433, 327);
        glVertex2d(418, 309);
        glVertex2d(418, 306);
        glEnd();
        plane4v(422.5, 438, 438, 424, 299.5, 317, 313.5, 297.5);
    }

    void bigWindow(double R, double G, double B)
    {
        glBegin(GL_QUAD_STRIP);
        glColor3ub(oldBrown);
        glVertex2d(422.5, 456);
        glVertex2d(426, 460);
        glVertex2d(422.5, 497);
        glVertex2d(426, 494.5);
        glVertex2d(485.5, 533);
        glVertex2d(482, 527);
        glVertex2d(485.5, 525.5);
        glVertex2d(482, 522);
        glEnd();

        glColor3ub(R, G, B);
        plane4v(426, 426, 482, 482, 460, 494.5, 527, 522);

        glColor3ub(white1);
        plane4v(441, 453, 442, 426.5, 476.5, 490, 504, 495);
        plane4v(455.5, 460, 451, 445.5, 492.5, 497.5, 509, 506);
    }

    void window(double R, double G, double B)
    {
        glBegin(GL_QUAD_STRIP);
        glColor3ub(193, 193, 193);
        glVertex2d(263, 364.5);
        glVertex2d(265.5, 366);
        glVertex2d(263, 399);
        glVertex2d(265.5, 399);
        glVertex2d(298.5, 420);
        glVertex2d(298.5, 418);
        glEnd();

        // Frame
        glColor3ub(oldBrown);
        plane4v(265.5, 265.5, 298, 298.5, 366.5, 399, 417.5, 384);

        // pane
        glColor3ub(R, G, B);
        plane4v(283.5, 283.5, 296.5, 296.5, 376.5, 407, 414.5, 383);
        plane4v(267, 267, 281, 281, 367.5, 398, 405.5, 375.5);

        glColor3ub(white1);
        plane4v(275.5, 279.5, 271, 267, 372.5, 374.5, 400, 398);
        plane4v(272.5, 275, 281, 281, 400.5, 402, 383, 375);
        plane4v(292, 296, 287, 283.5, 381, 383, 409, 407);
        plane4v(288.5, 291, 296.5, 296.5, 409.5, 411, 393.5, 386);

        // Create hat
        glBegin(GL_TRIANGLE_STRIP);

        glColor3ub(180, 74, 76);
        glVertex2d(254, 362.5);
        glVertex2d(261.5, 363.5);
        glVertex2d(254, 359);

        glColor3ub(231, 99, 95);
        glVertex2d(263, 353.5);
        glVertex2d(289, 380);
        glVertex2d(298.5, 374.5);
        glVertex2d(298.5, 384.5);
        triangle(289, 289, 298, 380, 383, 384.5);
        glEnd();
    }

    void garage()
    {
        glColor3ub(91, 91, 91);
        plane4v(412.5, 412.5, 494, 494, 520.5, 566, 613, 566);
        glColor3ub(gray);
        plane4v(409, 412.5, 412.5, 409, 518.5, 520.5, 566, 568);
    }
    void stair()
    {
        glBegin(GL_QUAD_STRIP);
        glColor3ub(210, 75, 69);
        glVertex2d(330.5, 577.5);
        glVertex2d(295.5, 558);
        glVertex2d(330.5, 572);
        glVertex2d(295.5, 552.5);
        glVertex2d(337, 567.5);
        glVertex2d(301.5, 548.5);
        glVertex2d(337, 562);
        glVertex2d(301.5, 543);
        glVertex2d(341.5, 558.5);
        glVertex2d(306.5, 540);
        glVertex2d(341.5, 553.5);
        glVertex2d(306.5, 534.5);
        glVertex2d(347.5, 548.5);
        glVertex2d(313.4, 530);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(186, 61, 57);
        glVertex2d(330.5, 577.5);
        glVertex2d(330.5, 572);
        glVertex2d(337, 567.5);
        glVertex2d(337, 562);
        glVertex2d(341.5, 558.5);
        glVertex2d(341.5, 553.5);
        glVertex2d(341.5, 553.5);
        glVertex2d(348.5, 548.5);
        glVertex2d(348, 567.5);
        glEnd();
    }
    void pot()
    {
        //flower
        glBegin(GL_QUAD_STRIP);
        glColor3ub(223, 223, 223);
        glVertex2d(279, 531);
        glVertex2d(279, 534.5);
        glVertex2d(294.5, 541);
        glVertex2d(294.5, 544.5);
        glVertex2d(301.5, 535.5);
        glVertex2d(301.5, 539.5);
        glVertex2d(286, 526);
        glEnd();
        plane4v(286, 301.5, 294.5, 279, 526, 535.5, 541, 531);
        glColor3ub(93, 220, 81);
        plane4v(286, 297, 294, 283, 528.5, 535.5, 538, 531);
    }
    void tree()
    {
        glBegin(GL_POLYGON);
        glColor3ub(96, 111, 16);
        for (int i = 180; i <= 360; i++)
        {
            double rad = i * 3.14 / 180;
            glVertex2d(247.5 + cos(rad) * 42 / 2, 523.5 + sin(rad) * 160 / 2);
        }
        glEnd();
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 182; i++)
        {
            double rad = i * 3.14 / 180;
            glVertex2d(247.5 + cos(rad) * 40 / 2, 523.5 + sin(rad) * 50 / 2);
        }
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(134, 153, 2);
        for (int i = 180; i <= 360; i++)
        {
            double rad = i * 3.14 / 180;
            glVertex2d(246.5 + cos(rad) * 33 / 2, 523.5 + sin(rad) * 150 / 2);
        }
        glEnd();
        glBegin(GL_POLYGON);

        for (int i = 0; i <= 182; i++)
        {
            double rad = i * 3.14 / 180;
            glVertex2d(246.5 + cos(rad) * 33 / 2, 523.5 + sin(rad) * 50 / 2);
        }
        glEnd();
    }
    void street()
    {
        glColor3ub(50, 41, 41);
        plane4v(192, 142.5, 401, 457, 529, 558.5, 708.5, 676);
        plane4v(142.5, 142.5, 401, 401, 558.5, 563.5, 713.5, 708.5);
        plane4v(401, 401, 457, 457, 708.5, 713.5, 681.5, 676);

        glColor3ub(235, 235, 235);
        plane4v(166, 170, 430.5, 426.5, 544.5, 542, 691.5, 693.5);
    }

    void lamp(double R, double G, double B)
    {
        glColor3ub(88, 58, 60);
        glBegin(GL_QUAD_STRIP);
        glVertex2d(512, 563);
        glVertex2d(507, 565);
        glVertex2d(524, 568.5);
        glVertex2d(524, 572.5);
        glVertex2d(537, 563.5);
        glVertex2d(541, 565.5);
        glEnd();
        glBegin(GL_QUAD_STRIP);
        glVertex2d(514.5, 554.5);
        glVertex2d(512, 563);
        glVertex2d(524, 558.5);
        glVertex2d(524, 568.5);
        glVertex2d(533.5, 554.5);
        glVertex2d(537, 563.5);
        glEnd();
        plane4v(514.5, 524, 533.5, 524, 554.5, 558.5, 554.5, 550.5);

        rectangle(521.5, 527, 444.5, 554.5);
        plane4v(521.5, 527, 531.5, 517, 444.5, 444.5, 440, 440);

        glBegin(GL_POLYGON);
        glColor3ub(R, G, B);
        for (int i = 0; i <= 360; i++)
        {
            double rad = i * 3.14 / 180;
            glVertex2d(524 + cos(rad) * 28 / 2, 425 + sin(rad) * 28 / 2);
        }
        glEnd();
    }
    void shadow()
    {
        // shadow tree1
        glBegin(GL_POLYGON);
        glColor3ub(94, 107, 40);
        for (int i = 0; i <= 360; i++)
        {
            double rad = i * 3.14 / 180;
            glVertex2d(251.25 + cos(rad) * 30 / 2, 550 + sin(rad) * 16.5 / 2);
        }
        glEnd();
        // shadow tree2
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 360; i++)
        {
            double rad = i * 3.14 / 180;
            glVertex2d(335.25 + cos(rad) * 30 / 2, 597 + sin(rad) * 16.5 / 2);
        }
        glEnd();
        // shadow tree3
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 360; i++)
        {
            double rad = i * 3.14 / 180;
            glVertex2d(455 + cos(rad) * 30 / 2, 660 + sin(rad) * 16.5 / 2);
        }
        glEnd();
    }
};

MyHome home;

void display(int status)
{
    if (status == 1)
    {
        glTranslated(0, -100, 0);
        home.land();
        home.grass();
        home.wall();
        home.rooftop();
        home.miniRooftop(yellow);
        home.bigWindow(yellow);
        home.garage();
        home.door(yellow);
        home.window(yellow);
        home.stair();

        home.street();
        glTranslatef(0, 80, 0);
        home.window(yellow);
        glTranslatef(52, -51, 0);
        home.window(yellow);
        glTranslatef(-80, -43, 0);
        home.pot();
        glTranslatef(25, 14.5, 0);
        home.pot();
        glTranslatef(67.5, 37.5, 0);
        home.pot();
        glTranslatef(35, 186, 0);
        glScalef(0.6, 0.6, 0);
        home.tree();
        glTranslatef(139.25, 81.5, 0);
        home.tree();
        glTranslatef(200.25, 107.5, 0);
        home.tree();
        if (lampGarden == -1)
        {
            glTranslatef(-215.25, -54, 0);
            home.lamp(white2);
            glTranslatef(-450.25, -194, 0);
            home.lamp(white2);
        }
        else
        {
            glTranslatef(-215.25, -54, 0);
            home.lamp(yellow);
            glTranslatef(-450.25, -194, 0);
            home.lamp(yellow);
        }
    }
    else
    {
        glTranslated(0, -100, 0);
        home.land();
        home.grass();
        home.wall();
        home.rooftop();
        home.miniRooftop(blue);
        home.bigWindow(blue);
        home.garage();
        home.door(blue);
        home.window(blue);
        home.stair();
        home.shadow();

        home.street();
        glTranslatef(0, 80, 0);
        home.window(blue);
        glTranslatef(52, -51, 0);
        home.window(blue);
        glTranslatef(-80, -43, 0);
        home.pot();
        glTranslatef(25, 14.5, 0);
        home.pot();
        glTranslatef(67.5, 37.5, 0);
        home.pot();
        glTranslatef(35, 186, 0);
        glScalef(0.6, 0.6, 0);
        home.tree();
        glTranslatef(139.25, 81.5, 0);
        home.tree();
        glTranslatef(200.25, 107.5, 0);
        home.tree();
        if (lampGarden == -1)
        {
            glTranslatef(-215.25, -54, 0);
            home.lamp(white2);
            glTranslatef(-450.25, -194, 0);
            home.lamp(white2);
        }
        else
        {
            glTranslatef(-215.25, -54, 0);
            home.lamp(yellow);
            glTranslatef(-450.25, -194, 0);
            home.lamp(yellow);
        }
    }
}

/* Callbacks Function */
static void error_callback(int error, const char *description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        lampGarden *= -1;
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        status *= -1;
    }
}

int main(void)
{
    /* Creating Windows */
    GLFWwindow *window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        ;
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(800, 800, "G64190074 - My House", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    /* Registering Callbacks */
    glfwSetKeyCallback(window, key_callback);
    // //    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    /* MAIN LOOP */
    while (!glfwWindowShouldClose(window))
    {
        /* Preparing Frame Creation */
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, 800, 800, 0, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        if (status == -1)
        {
            glClearColor(135.0 / 255.0f, 206.0 / 255.0f, 235.0 / 255.0f, 0.0f);
        }
        else
        {
            glClearColor(35.0 / 255.0f, 35.0 / 255.0f, 35.0 / 255.0f, 0.0f);
        }

        display(status);

        /* Handling Frame Changes */
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    /* Destroying Windows */
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}