#!/bin/bash
# This script generates 50 test cases for SHA256 unit tests
# A SHA256 hash value is calculated by the script from a random challenge of random length
# Both the random challenge and the hash are included in the test cases for the calculation to
# compare against.
# Created by John Yu

# pick a random number between two values
random_number(){
	num1=$1
	num2=$2
	shuf -i "$1"-"$2" -n 1 
}

# generate random data and pack it with xxd
random_data(){
	length=$1
	head --bytes="$length" /dev/urandom | xxd -p
}

# converts packed xxd data to C array content
format_data(){
	data=$1
	echo "$data" | xxd -r -p | xxd -i
}

# counts the number of bytes in packed xxd data
data_length(){
	data=$1
	echo "$data" | xxd -r -p | wc --bytes
}

# converts packed xxd data to hash value in packed xxd format
hash_data(){
	data=$1
	echo "$data" | xxd -r -p | shasum -a256 | head --bytes=64
}

# prints test cases
print_test(){
	name=$1
	data=$2
	result=$3
	len=$(data_length "$data")
	echo -e "TEST(SHA256, $testname) {"
	echo -e "\tstruct sha256_inst instance;"
	echo -e "\tuint8_t result[SHA256_DIGEST_SIZE];"
	echo -e "\tsha256_begin(&instance);"
	echo -e "\tconst uint8_t test_data[$len] = {"
	format_data "$data" | sed 's/^/\t\t/'
	echo -e "\t};"
	echo -e "\tsha256_update(&instance, test_data, $len);"
	echo -e "\tsha256_finish(&instance, &result);"
	echo -e "\tEXPECT_THAT(result, testing::ElementsAre("
	format_data "$result" | sed 's/^/\t\t/'
	echo -e "\t));"
	echo -e "}"
}

gen_test() {
	num_cases=$1
	for i in $(seq 1 "$num_cases")
	do
		testname="Test$i"
		len=$(random_number 1 300)
		challenge=$(random_data "$len")
		result=$(hash_data "$challenge")
		print_test $testname "$challenge" "$result"
	done
}

gen_test 50 > $1

