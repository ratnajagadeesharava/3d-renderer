#pragma once

#include "typedefs.h"
#include "VecMath.h"
class ObjFile
{
public:
	ObjFile(string fileName);
	//~ObjFile();
private:
	string fileName;
public:
	vector<Vector3f> vertices;
	vector<Vector3f> normals;
	vector<vector<unsigned>> faces;

private:
	void read_vertices(string& line);
	void read_normals(string& line);
	void read_faces(string& line);
	void read_file();
	void formatLine(string& line);
	

};

