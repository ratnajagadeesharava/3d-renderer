#include "ObjFile.h"

#include <sstream>
#include <fstream>

ObjFile::ObjFile(string fileName)
{
	this->fileName = fileName;
	read_file();
}

void ObjFile::read_vertices(string& line)
{
    line.erase(0, 3);
    float x, y, z;
    istringstream(line) >> x >> y >> z;
    vertices.push_back(Vector3f(x, y, z));
}

void ObjFile::read_normals(string& line)
{
    line.erase(0, 2);
    float x, y, z;
    istringstream(line) >> x >> y >> z;
    normals.push_back(Vector3f(x, y, z));
}

void ObjFile::read_faces(string& line)
{
    line.erase(0, 2);
    stringstream ss(line);
    string token;
    vector<unsigned> result;
    while (getline(ss, token, ' ')) {
        std::stringstream ssToken(token);
        std::string numStr;
        while (std::getline(ssToken, numStr, '/')) {
            result.push_back(std::stoi(numStr));
        }
    }
    faces.push_back(result);
}

void ObjFile::read_file()
{
    ifstream file(fileName);
    if (!file) {
        cerr << "Error: sphere.obj could not be opened" << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
		formatLine(line);
    }
    file.close();
}

void ObjFile::formatLine(string& line)
{
    switch (line[0]) {
    case 'v':
		line[1] == 'n' ? read_normals(line) : read_vertices(line);
        break;
    case 'f':
		read_faces(line);
        break;
    };
}
