#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

void SDL_ExitWithError(const char *message);

int main(int argc, char *argv[]){


	SDL_Window * window = NULL; // Creation du pointeur de la fenetre
	SDL_Renderer *renderer = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		SDL_ExitWithError("Initialisation SDL");
		// message si l'initialisation n'est pas correcte

	}

	//Creation fenetre + rendu
	if(SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer) != 0)
		SDL_ExitWithError("Impossible de creer la fenetre et le rendu");
	if(SDL_SetRenderDrawColor(renderer, 112, 168, 237, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Impossible de changer la couleur du rendu");

	if(SDL_RenderDrawPoint(renderer, 100, 450) != 0)
		SDL_ExitWithError("Impossible de dessiner le point");
	if(SDL_RenderDrawLine(renderer, 50, 50, 500, 500) != 0)
		SDL_ExitWithError("Impossible de tracer une line");

	SDL_Rect rectangle;
	rectangle.x = 300;
	rectangle.y = 300;
	rectangle.w = 200;
	rectangle.h = 120;

	if(SDL_RenderDrawRect(renderer, &rectangle) != 0)
		SDL_ExitWithError("Impossible de creer le rectangle");


	SDL_RenderPresent(renderer);

	if(SDL_RenderClear(renderer) != 0)
		SDL_ExitWithError("Effacement rendu a echoue");

	SDL_Delay(6000); // Le temps d'ouverture de la fenetre en ms

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window); // Destruction de la fenetre

	SDL_Quit(); // Quitter lan fenetre
	printf("\nLa fenetre est creer\n");
	return EXIT_SUCCESS;
}

void SDL_ExitWithError(const char *message){
	SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}
