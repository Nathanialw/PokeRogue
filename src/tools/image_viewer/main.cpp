//
// Created by nathanial on 3/3/26.
//

#include "SDL3/SDL.h"

#include "globals.h"
#include "images.h"
#include "input.h"
#include "rendering.h"
#include "text.h"
#include "update.h"


/*  Get the image folders
 *  get the images for the selected folder
 *  display the images
 *  let the user delete images
 *  let the user select an image as USED for each folder
 */
int main()
{
    Renderer renderer;
    const uint16_t h = (128 * DISPLAYED_IMAGE_COUNT) + BTN_H;
    const uint16_t w = (BTN_W * 5) + (128 * DISPLAYED_IMAGE_COUNT);
    if (!renderer.Init("Image Viewer", w, h))
        return -1;

    ImageData images;
    if (!images.Init())
        return -1;

    UI ui;
    ui.Init();

    Text text;
    text.InitText(renderer.GetSDLRenderer());
    text.PopulateTextTextures(renderer.GetSDLRenderer(), images.entity_list);

    renderer.CreateTextures(images);
    renderer.Render(ui, text, images.GetEntityCount(), images.GetImageCount());

    while (g_sdl.Running())
    {
        ProcessInput(renderer, text, images, ui);
        Update(images);
        renderer.Render(ui, text, images.GetEntityCount(), images.GetImageCount());
    }


    SDL_Quit();
    return 0;
}
