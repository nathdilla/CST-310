#include <iostream>
#include <vector>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other Libs
#include <SOIL/SOIL.h>
// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other includes
#include "./headers/Shader.h"
#include "./headers/ndraw.h"

using namespace std;

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

void drawPlane(GLfloat v1x, GLfloat v1y, GLfloat v1z,
                GLfloat v2x, GLfloat v2y, GLfloat v2z,
                GLfloat v3x, GLfloat v3y, GLfloat v3z,
                GLfloat v4x, GLfloat v4y, GLfloat v4z);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 1200;

GLfloat vertices[700]; //convert vector to rendering array
GLfloat g_color_buffer_data[700];

// The MAIN function, from here we start the application and run the game loop
int main()
{
    
    
    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "More 3D example", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // Set the required callback functions
    glfwSetKeyCallback(window, key_callback);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    glewInit();

    // Define the viewport dimensions
    glViewport(0, 0, WIDTH, HEIGHT);

    // Setup OpenGL options
    glEnable(GL_DEPTH_TEST);


    // Build and compile our shader program
    Shader ourShader("./cube_shaders/MoreCubes.vs", "./cube_shaders/MoreCubes.frag");

    ndraw::setColorOfDraw(0.910f,  0.920f,  0.846);

    ndraw::drawPlane(//BACK WALL
            -1.5f, -1.5f, -0.5f,
             1.0f, -1.5f, -0.5f,
             1.0f,  2.0f, -0.5f,
            -1.5f,  2.0f, -0.5f
    );

    ndraw::drawPlane(//RIGHT WALL
             1.0f, -1.5f, 2.0f,
             1.0f, -1.5f, -0.5f,
             1.0f,  2.0f, -0.5f,
             1.0f,  2.0f, 2.0f
    );

    ndraw::setColorOfDraw(0.140f,  0.101f,  0.033f);

    ndraw::drawPlane(//FLOOR
             -1.5f, -1.5f, -0.5f,
             1.0f, -1.5f, -0.5f,
             1.0f, -1.5f,  2.0f,
             -1.5f, -1.5f,  2.0f
    );

    ndraw::setColorOfDraw(0.180f,  0.180f,  0.180f);

    ndraw::drawPlane(//BACK WALL BASEBOARD
            -1.5f, -1.5f, -0.499f,
            1.0f, -1.5f, -0.499f,
            1.0f, -1.2f, -0.499f,
            -1.5f, -1.2f, -0.499f
    );

    ndraw::drawPlane(//RIGHT WALL BASEBOARD
            0.99f, -1.5f, 2.0f,
            0.99f, -1.5f, -0.5f,
            0.99f, -1.2f, -0.5f,
            0.99f, -1.2f, 2.0f
    );

    ndraw::setColorOfDraw(0.770f,  0.682f,  0.531f);

    ndraw::drawPlane(//SHELF 1 -- top
            -0.6f, 0.7f, -0.5f,
             0.9f, 0.7f, -0.5f,
             0.9f, 0.7f,  0.3f,
             -0.6f, 0.7f,  0.3f
    );

    ndraw::drawPlane(//SHELF 2
            -0.6f, 0.0f, -0.5f, 
            0.9f, 0.0f, -0.5f, 
            0.9f, 0.0f,  0.3f, 
            -0.6f, 0.0f,  0.3f
    );

    ndraw::drawPlane(//SHELF 3
            -0.6f, -0.7f, -0.5f, 
            0.9f, -0.7f, -0.5f, 
            0.9f, -0.7f,  0.3f, 
            -0.6f, -0.7f,  0.3f
    );

    ndraw::drawPlane(//SHELF 4 -- bottom
            -0.6f, -1.4f, -0.5f, 
            0.9f, -1.4f, -0.5f, 
            0.9f, -1.4f,  0.3f, 
            -0.6f, -1.4f,  0.3f
    );

    ndraw::drawPlane(//SHELF VERTICAL
            0.9f, 0.7f, -0.5f,
            0.9f, -1.4f, -0.5f,
            0.9f, -1.4f,  0.3f,
            0.9f, 0.7f, 0.3f
    );

    ndraw::drawPlane(//SHELF VERTICAL
            -0.6f, 0.7f, -0.5f,
            -0.6f, -1.4f, -0.5f,
            -0.6f, -1.4f,  0.3f,
            -0.6f, 0.7f, 0.3f
    );

    ndraw::drawPlane(//SHELF VERTICAL
            0.15f, 0.7f, -0.5f,
            0.15f, -1.4f, -0.5f,
            0.15f, -1.4f,  0.3f,
            0.15f, 0.7f, 0.3f
    );

    ndraw::setColorOfDraw(0.0f,0.0f,0.0f);

    ndraw::drawCylinder(-0.3f, 1.05f, -0.1f,10,0.01f,0.7f);
//     ndraw::drawCylinder(-0.3f, 0.05f, -0.1f,10,0.8f,0.7f);
    // draw ends



     for (int i = 0; i < ndraw::getSizeOfDraw(); i++) { //convert vector to array
        vertices[i] = ndraw::getVertexFromDraw(i);
    }
     for (int i = 0; i < ndraw::getSizeOfColor(); i++) { //convert colors to array
        g_color_buffer_data[i] = ndraw::getColorFromVertex(i);
    }

    std::cout << ndraw::getSizeOfColor() << "\n";
    std::cout << ndraw::getSizeOfDraw();
    

    GLuint VBO, VAO, colorbuffer;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glGenBuffers(1, &colorbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // glBufferData(GL_ARRAY_BUFFER, ndraw::getSizeOfDraw(), &ndraw::getVerts()[0], GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    // TexCoord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    glBindVertexArray(0); // Unbind VAO


    // Load and create a texture 
    GLuint texture1;
    GLuint texture2;
    // ====================
    // Texture 1
    // ====================
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load, create texture and generate mipmaps
    int width, height;
    unsigned char* image = SOIL_load_image("wall_texture.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
    // ===================
    // Texture 2
    // ===================
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load, create texture and generate mipmaps
    image = SOIL_load_image("wood_floor_texture.png", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);


    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        // Render
        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // // Bind Textures using texture units
        // glActiveTexture(GL_TEXTURE0);
        // glBindTexture(GL_TEXTURE_2D, texture1);
        // glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);
        // glActiveTexture(GL_TEXTURE1);
        // glBindTexture(GL_TEXTURE_2D, texture2);
        // glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture2"), 1);

        // Activate shader
        ourShader.Use();

        // Create transformations
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection;
        
        GLfloat angle = 0.0f * 1; // this together with below won't make it spin
        model = glm::rotate(model, angle, glm::vec3(0.0f, 1.0f, 0.0f)); // this won't make rotate
        
        model = glm::rotate(model, 2*sin((GLfloat)glfwGetTime()) * 0.1f, glm::vec3(-0.1f, 0.0f, 0.0f)); // bounce
        
        GLfloat viewAngle = 0.0f * 1;
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -8.0f));// -3
        view = glm::rotate(view, viewAngle, glm::vec3(-0.1f, 0.0f, 0.0f));
        // Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
        // Get their uniform location
        GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
        GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
        GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
        // Pass them to the shaders
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        // Draw container
        glBindVertexArray(VAO);
        glColor3f(0.5f, 0.0f, 1.0f);
        glDrawArrays(GL_TRIANGLES, 0, 144);
        glBindVertexArray(0);

        // Swap the screen buffers
        glfwSwapBuffers(window);
    }
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

