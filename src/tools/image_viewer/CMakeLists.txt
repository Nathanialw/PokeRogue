add_executable(ImageViewer
        main.cpp

        constants.h
        globals.cpp

        init.cpp
        input.cpp
        rendering.cpp
        update.cpp
        images.cpp
        db.cpp
        ui.cpp
        text.cpp
        tile_map_preview.cpp

)


target_include_directories(ImageViewer PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)


target_link_libraries(ImageViewer PRIVATE
        SDL3::SDL3-static
        SDL3_image
        SDL3_ttf
        stdc++
        sqlite3
)