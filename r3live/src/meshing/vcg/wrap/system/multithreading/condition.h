#ifndef MT_CONDITION_H
#define MT_CONDITION_H

#include "base.h"
#include "mutex.h"

#include <pthread.h>

namespace mt
{

class condition
{
	MT_PREVENT_COPY(condition)

	public:

		typedef condition this_type;
		typedef void      base_type;

		condition(void)
		{
			pthread_cond_init(&(this->c), 0);
		}

		~condition(void)
		{
			pthread_cond_destroy(&(this->c));
		}

		void signal(void)
		{
			pthread_cond_signal(&(this->c));
		}

		void broadcast(void)
		{
			pthread_cond_broadcast(&(this->c));
		}

		void wait(mutex & m)
		{
			pthread_cond_wait(&(this->c), &(m.m));
		}

	private:

		pthread_cond_t c;
};

}

#endif // MT_CONDITION_H
Fake commit 41 on 2024-12-28T00:00:00
Fake commit 94 on 2024-12-08T00:00:00
