int int_array_check(int needle, int *haystack[], int length){
    
    // Checks the array    
    int i;

    for(i = 0; i < length; i++)
    {     
        // printf("\n%d %d\n", needle, *haystack[i]);
        if(needle == *haystack[i])
            return *haystack[i];
    }

    return -1;
}

int int_array_compare(int *array1[], int *array2[], int length[2]){

    // Counters
    int i = 0;
    int j = 0;

    // Auxiliary variable for matching elements
    int match = 0;

    // Array 1
    for(i = 0; i < length[0]; i++)
    {
        // Array 2
        for(j = 0; j < length[1]; j++)
        {
            // If elements match
            if(*array2[j] == *array1[i]){
                match = 1;
                break;
            }
        }

        // If element didn't match
        if(match == 0)
            return 0;
            
        // Resets aux in case of element matching
        match = 0;
    }

    return 1;
}
