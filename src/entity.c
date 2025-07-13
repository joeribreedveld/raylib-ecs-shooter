int next_entity = 0;

int create_entity()
{
	return next_entity++;
}

void reset_entities()
{
	next_entity = 0;
}