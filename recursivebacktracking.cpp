/* pseudocode

bool solve(configuration conf){
	if (no more choices) // base case
		return (conf is goal state)
	
	for(all available choices){
		try one choice c;
		//solve from here, if work out, youre done

		if(solve(choice made with conf c))
			return true

		unamke the choice c
	}

	return false

}


*/