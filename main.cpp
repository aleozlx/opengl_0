#include <iostream>

extern "C" {

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>

}

void _init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 640.0/480.0, 1.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
}

void _display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0, 2.0, -5.0);
    glVertex3f(-2.0, -2.0, -5.0);
    glVertex3f(2.0, -2.0, -5.0);
    glEnd();
}

int main(int argc, char **argv) {
    // std::cout << "Hello, world!" << std::endl;
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("My Game Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 480,
        /* SDL_WINDOW_FULLSCREEN | */ SDL_WINDOW_OPENGL);
    SDL_GLContext glcontext = SDL_GL_CreateContext(window);
    
    bool running = true;
    Uint32 start;
    SDL_Event event;
    _init();
    while(running){
        start = SDL_GetTicks();
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
        
        _display();
        SDL_GL_SwapWindow(window);
        if(1000/30>(SDL_GetTicks()-start)){
            SDL_Delay(1000/30-(SDL_GetTicks()-start));
        }
            
    }
    
    SDL_GL_DeleteContext(glcontext);
    SDL_Quit();
    
    return 0;
}
