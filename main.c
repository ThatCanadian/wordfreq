#include <stdio.h>
#include <analytics.h>

void my_callback(const char* word, int count)
{
	fprintf(stdout, "%s :\t%d\n", word, count);
}

int main()
{
	int limit = 10; //Set to 10 for testing purposes, later will be variable
	word_map_t wordMap;
	
	const word_list_t wordList = split_word(stdin);
	
	wordMap = count_words(word_list_t);
	word_list_free(wordList); //done with the word list
	
	sort_counted_words(wordMap, 0);
	
    fprintf(stdout, "Most common words:\n");
	word_map_nforeach(wordMap, my_callback, limit);
	
}