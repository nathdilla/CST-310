#include <iostream>
#include <GL/glew.h>
#include <vector>

class ndraw
{
    private:
        static std::vector<GLfloat> verts;
        static std::vector<GLfloat> colors;
        static std::vector<GLfloat> currentColor;
    public:

        static void setColorOfDraw(GLfloat r, GLfloat g, GLfloat b)
        {
            currentColor.at(0) = r;
            currentColor.at(1) = g;
            currentColor.at(2) = b;
        }

        static int getSizeOfDraw()
        {
            return verts.size();
        }

        static int getSizeOfColor()
        {
            return colors.size();
        }

        static std::vector<GLfloat> getVerts()
        {
            return verts;
        }

        static GLfloat getVertexFromDraw(int i)
        {
            return verts[i];
        }

        static GLfloat getColorFromVertex(int i)
        {
            return colors[i];
        }

        static void pushToVertices(GLfloat v)
        {
            verts.push_back(v);
        }

        static void pushToColor()
        {
            colors.push_back(currentColor[0]);
            colors.push_back(currentColor[1]);
            colors.push_back(currentColor[2]);
        }

        static void drawTri(GLfloat v1x, GLfloat v1y, GLfloat v1z,
                GLfloat v2x, GLfloat v2y, GLfloat v2z,
                GLfloat v3x, GLfloat v3y, GLfloat v3z)
        {
            pushToVertices(v1x);//v
            pushToVertices(v1y);
            pushToVertices(v1z);
            pushToColor();

            pushToVertices(0.0f);//vn
            pushToVertices(0.0f);

            pushToVertices(v2x);//v
            pushToVertices(v2y);
            pushToVertices(v2z);
            pushToColor();

            pushToVertices(1.0f);//vn
            pushToVertices(0.0f);

            pushToVertices(v3x);//v
            pushToVertices(v3y);
            pushToVertices(v3z);
            pushToColor();

            pushToVertices(1.0f);//vn
            pushToVertices(1.0f);
        }

        static void drawPlane(GLfloat v1x, GLfloat v1y, GLfloat v1z,
                GLfloat v2x, GLfloat v2y, GLfloat v2z,
                GLfloat v3x, GLfloat v3y, GLfloat v3z,
                GLfloat v4x, GLfloat v4y, GLfloat v4z)
        {
            drawTri(
                v1x, v1y, v1z,
                v2x, v2y, v2z,
                v3x, v3y, v3z
            );
            drawTri(
                v3x, v3y, v3z,
                v4x, v4y, v4z,
                v1x, v1y, v1z
            );
        }

        //cylinder
        static void drawCylinder(GLfloat originX, GLfloat originZ, GLfloat originY, int numPoints, GLfloat radius, GLfloat height)
        {
            float polyAngle = 2 * 3.14159267 / numPoints;
            for (int i = 1; i < numPoints+1; i++)
            {
                GLfloat x = originX + radius * sin(i * polyAngle);
                GLfloat y = originY + radius * cos(i * polyAngle);

                GLfloat prevX = originX + radius * sin((i-1) * polyAngle);
                GLfloat prevY = originY + radius * cos((i-1) * polyAngle);

                ndraw::drawPlane(
                    x, originZ-(height/2), y,
                    prevX, originZ-(height/2), prevY,
                    prevX, originZ+(height/2), prevY,
                    x, originZ+(height/2), y
                );
            }
        }

        // GLfloat * completeVerts()
        // {
        //     static GLfloat vertices[verts.size()];

        //     for (int i = 0; i < 30; i++) {
        //         vertices[i] = verts.size()[i];
        //     }

        //     return vertices;
        // }
};

std::vector<GLfloat> ndraw::verts; //initializer
std::vector<GLfloat> ndraw::colors; //initializer
std::vector<GLfloat> ndraw::currentColor(3,1.0f);

