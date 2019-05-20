static void	glerr(const char *s) // debug
{
	GLenum	err;

	err = glGetError();
	switch(err)
	{
		case GL_NO_ERROR :
			break ;
		case GL_INVALID_ENUM :
			fprintf(stderr, "%s : GL_INVALID_ENUM\n", s);
			fflush(stderr);
			break ;
		case GL_INVALID_VALUE :
			fprintf(stderr, "%s : GL_INVALID_VALUE\n", s);
			fflush(stderr);
			break ;
		case GL_INVALID_OPERATION :
			fprintf(stderr, "%s : GL_INVALID_OPERATION\n", s);
			fflush(stderr);
			break ;
		case GL_STACK_OVERFLOW :
			fprintf(stderr, "%s : GL_STACK_OVERFLOW\n", s);
			fflush(stderr);
			break ;
		case GL_STACK_UNDERFLOW :
			fprintf(stderr, "%s : GL_STACK_UNDERFLOW\n", s);
			fflush(stderr);
			break ;
		case GL_OUT_OF_MEMORY :
			fprintf(stderr, "%s : GL_OUT_OF_MEMORY\n", s);
			fflush(stderr);
			break ;
		case GL_INVALID_FRAMEBUFFER_OPERATION :
			fprintf(stderr, "%s : GL_INVALID_FRAMEBUFFER_OPERATION\n", s);
			fflush(stderr);
			break ;
		case GL_CONTEXT_LOST :
			fprintf(stderr, "%s : GL_CONTEXT_LOST\n", s);
			fflush(stderr);
			break ;
		case GL_TABLE_TOO_LARGE :
			fprintf(stderr, "%s : GL_TABLE_TOO_LARGE\n", s);
			fflush(stderr);
			break ;

	}
}
