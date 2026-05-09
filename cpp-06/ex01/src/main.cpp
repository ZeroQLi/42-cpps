#include "../includes/Serializer.hpp"

int	main(void)
{
	Data	*data = new Data();
	data->name = "mtangalv";
	data->rank = 5;
	data->status = true;

	std::cout << "Original: \n"
			  << data->name << "\n"
			  << data->rank << "\n"
			  << (data->status ? "true" : "false") << "\n\n";

	uintptr_t	serialized = Serializer::serialize(data);
	std::cout << "Serialized: " << serialized << "\n\n";

	Data	*deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized: \n" 
			  << deserialized->name << "\n" 
			  << deserialized->rank << "\n" 
			  << (deserialized->status ? "true" : "false") << std::endl;
	return (0);
}