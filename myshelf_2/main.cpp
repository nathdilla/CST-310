#include <iostream>
#include <cmath>
#include <vector>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other includes
#include "Shader.h"
#include "./headers/ndraw.h"

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 1200;

GLfloat vertices[100000]; //convert vector to rendering array
GLfloat g_color_buffer_data[100000];

// Light attributes
glm::vec3 lightPos(0.0f,0.0f,0.0f);

// Deltatime
GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
GLfloat lastFrame = 0.0f;  	// Time of last frame

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
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // Set the required callback functions
    // glfwSetKeyCallback(window, key_callback);
    // glfwSetCursorPosCallback(window, mouse_callback);
    // glfwSetScrollCallback(window, scroll_callback);

    // GLFW Options
    // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    glewInit();

    // Define the viewport dimensions
    glViewport(0, 0, WIDTH, HEIGHT);

    // OpenGL options
    glEnable(GL_DEPTH_TEST);


//     // Build and compile our shader program
//     Shader lightingShader("./shaders/lighting.vs", "./shaders/lighting.frag");
//     Shader lampShader("./shaders/MoreCubes.vs", "./shaders/MoreCubes.frag");

     // Build and compile our shader program
    Shader worldShader("./shaders/MoreCubes.vs", "./shaders/MoreCubes.frag");

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

    ndraw::drawPlane(//SHELF VERTICAL +72
            0.15f, 0.7f, -0.5f,
            0.15f, -1.4f, -0.5f,
            0.15f, -1.4f,  0.3f,
            0.15f, 0.7f, 0.3f
    );

//     ndraw::drawPlane();
    //LAMP ************************************************************** = 120 VERTS
    ndraw::setColorOfDraw(0.0f,0.0f,0.0f);
    ndraw::drawCylinder(0.0f, -1.25f, 0.0f,10,0.075f,2.65f);//pole +60
    ndraw::setColorOfDraw(1.00f, 0.993f, 0.920f);
    ndraw::drawCylinder(0.0f, -0.25f, 0.0f,10,1.0f,1.75f);//shade +60
    //*******************************************************************

    //MAT *************************************************************** = 60 VERTS
    ndraw::setColorOfDraw(0.340f, 0.164f, 0.0204f);
    ndraw::drawCylinder(0.0f, 0.0f, 0.0f,10,0.1f,1.6f);//pole +60

    //*******************************************************************
    ndraw::setColorOfDraw(0.95f, 0.95f, 0.95f);
    ndraw::drawSphere(10,10, 1.0f); //600

        ndraw::setColorOfDraw(0.45f, 0.45f, 0.45f);

        // for(int i = 0; i < 1; i++)
        // {
          ndraw::drawSphere(10,10, 1.0f); //600
        // }

   //rubiks
    ndraw::setColorOfDraw(1.0f, 0.0f, 0.0f);
    ndraw::drawPlane(//BACK WALL 
            -1.0f, -1.0f, -1.0f,
             1.0f, -1.0f, -1.0f,
             1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f
    );
    ndraw::setColorOfDraw(0.0f, 1.0f, 0.0f);
    ndraw::drawPlane(//BACK WALL 
            -1.0f, -1.0f, 1.0f,
             1.0f, -1.0f, 1.0f,
             1.0f,  1.0f, 1.0f,
            -1.0f,  1.0f, 1.0f
    );
    ndraw::setColorOfDraw(0.0f, 0.0f, 1.0f);
    ndraw::drawPlane(//BACK WALL 
             1.0f, -1.0f, -1.0f,
             1.0f, -1.0f, 1.0f,
             1.0f,  1.0f, 1.0f,
             1.0f,  1.0f, -1.0f
    );
    ndraw::setColorOfDraw(1.0f, 0.0f, 1.0f);
    ndraw::drawPlane(//BACK WALL 
             -1.0f, -1.0f, -1.0f,
             -1.0f, -1.0f, 1.0f,
             -1.0f,  1.0f, 1.0f,
             -1.0f,  1.0f, -1.0f
    );
    ndraw::setColorOfDraw(1.0f, 1.0f, 0.0f);
    ndraw::drawPlane(//BACK WALL 
             -1.0f, -1.0f, -1.0f,
             -1.0f,  1.0f, -1.0f,
             -1.0f,  1.0f, 1.0f,
             -1.0f, -1.0f, 1.0f
    );
    ndraw::setColorOfDraw(0.0f, 1.0f, 1.0f);
    ndraw::drawPlane(//BACK WALL 
             -1.0f,  1.0f, -1.0f,
             1.0f,  1.0f, -1.0f,
             1.0f,  1.0f, 1.0f,
             -1.0f,  1.0f, 1.0f
    );
    


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

//     // Then, we set the light's VAO (VBO stays the same. After all, the vertices are the same for the light object (also a 3D cube))
//     GLuint lightVAO;
//     glGenVertexArrays(1, &lightVAO);
//     glBindVertexArray(lightVAO);
//     // We only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need.
//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     // Set the vertex attributes (only position data for the lamp))
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0); // Note that we skip over the normal vectors
//     glEnableVertexAttribArray(0);
//     glBindVertexArray(0);
    

    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Calculate deltatime of current frame
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
        // do_movement();

        // Clear the colorbuffer
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // / Use cooresponding shader when setting uniforms/drawing objects
        // lightingShader.Use();
        // GLint objectColorLoc = glGetUniformLocation(lightingShader.Program, "objectColor");
        // GLint lightColorLoc  = glGetUniformLocation(lightingShader.Program, "lightColor");
        // GLint lightPosLoc    = glGetUniformLocation(lightingShader.Program, "lightPos");
        // glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);
        // glUniform3f(lightColorLoc,  1.0f, 1.0f, 1.0f);
        // glUniform3f(lightPosLoc,    lightPos.x, lightPos.y, lightPos.z);

        GLint modelLoc;
        GLint viewLoc;
        GLint projLoc;

        // // Create camera transformations
        glm::mat4 view = glm::translate(view, glm::vec3(0.0f, 0.0f, -8.0f));// -3
        // view = glm::translate(view, glm::vec3(0.0f,0.0f,-8.0f));
        // // view = camera.GetViewMatrix();
        glm::mat4 projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
        // // Get the uniform locations
        // GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
        // GLint viewLoc  = glGetUniformLocation(lightingShader.Program,  "view");
        // GLint projLoc  = glGetUniformLocation(lightingShader.Program,  "projection");
        // // Pass the matrices to the shader
        // glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        // glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        // Draw the container (using container's vertex attributes)
        glBindVertexArray(VAO);
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, (GLfloat)0.5f, glm::vec3(0.5f,0.5f,0.5f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        // glDrawArrays(GL_TRIANGLES, 0, 200);
        glBindVertexArray(0);

        worldShader.Use();

        // Create transformations
        model = glm::mat4(1.0f);
        view = glm::mat4(1.0f);
        // glm::mat4 projection;
        
        GLfloat angle = 0.0f * 1; // this together with below won't make it spin
        model = glm::rotate(model, angle, glm::vec3(0.0f, 1.0f, 0.0f)); // this won't make rotate
        
        GLfloat viewAngle = 0.0f * 1;
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));// -3
        // view = glm::rotate(view, viewAngle, glm::vec3(-0.1f, 0.0f, 0.0f));
        // view = glm::rotate(view, ((GLfloat)glfwGetTime()) * 0.1f, glm::vec3(0.05f, 0.1f, 0.0f)); // bounce
        // Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
        // Get their uniform location
        modelLoc = glGetUniformLocation(worldShader.Program, "model");
        viewLoc = glGetUniformLocation(worldShader.Program, "view");
        projLoc = glGetUniformLocation(worldShader.Program, "projection");
        // Pass them to the shaders
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        

        // Draw container
        glBindVertexArray(VAO);//lightVao
        glColor3f(0.5f, 0.0f, 1.0f);
        glDrawArrays(GL_TRIANGLES, 0, 72); //RENDER STRAIGHT OBJECTS

        model = glm::translate(model, glm::vec3(-0.2f, 1.5f, 0.0f));
        model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 72, 120); //RENDER LAMP

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.85f, -0.7f, 0.0f));
        model = glm::rotate(model,(GLfloat)0.15f, glm::vec3(0.0f, 0.0f, -0.1f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 192, 60); //RENDER MAT

        model = glm::mat4(1.0f);
        
        model = glm::translate(model, glm::vec3(-0.45f, 0.8f, 0.0f));
        model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));
        // model = glm::rotate(model,(GLfloat)0.15f, glm::vec3(0.0f, 0.0f, -0.1f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 252, 600); //RENDER ALEXA

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.1f, 0.2f, 0.0f));
        model = glm::scale(model, glm::vec3(0.025f, -0.025f, 0.025f));
        // model = glm::rotate(model,(GLfloat)0.15f, glm::vec3(0.0f, 0.0f, -0.1f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 852, 600); //RENDER BALL

        for(int i = 0; i<4; i++)
        {
                model = glm::translate(model, glm::vec3(-2.0f, 0.0f, 0.0f));
                glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
                glDrawArrays(GL_TRIANGLES, 852, 600); //RENDER BALL
        }

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.1f, -0.6f, 0.0f));
        model = glm::scale(model, glm::vec3(0.05f, 0.05f, 0.05f));
        // model = glm::rotate(model,(GLfloat)0.5f, glm::vec3(1.0f, 0.0f, 0.0f));
        for(int i = 0; i < 3; i++)
        {
                model = glm::rotate(model,(GLfloat)1.0f*i*2, glm::vec3(0.5f, 0.0f, 0.0f));
                model = glm::translate(model, glm::vec3(-3.0f, 0.0f, 0.0f));
                glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
                glDrawArrays(GL_TRIANGLES, 1452, 36); //RENDER cube
        }
        
        

        glBindVertexArray(0);

        // Swap the screen buffers
        glfwSwapBuffers(window);
    }

    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}