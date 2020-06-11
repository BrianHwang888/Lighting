#ifndef __AXIES_H__
#define __AXIES_H__

#include"color_object.h"

class Axies : public color_obj
{
public:
	Axies();
	Axies(const Axies& other);
	void gen_buffer(GLuint program) override;
	void draw() override;
	void read_file(const char* file) override;

	Axies& operator=(const Axies& rhs);


private:
};
#endif // !__AXIES_H__
