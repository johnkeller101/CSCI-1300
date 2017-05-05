//
//  Name            John Keller
//  Recitation TA   Jason Zietz
//  Assignment #    4
//

#include <iostream>

using namespace std;

float calcSimilarity(string sequenceOne, string sequenceTwo);
void listSequencePositions(string genomeSequence, string genomeName, string seq);
void compare3Genomes(string genome1, string name1, string genome2, string name2, string genome3, string name3, string seq);

// Define the DNA Sequences
string DNA[3][2] = {{"Human","CGCAAATTTGCCGGATTTCCTTTGCTGTTCCTGCATGTAGTTTAAACGAGATTGCCAGCACCGGGTATCATTCACCATTTTTCTTTTCGTTAACTTGCCGTCAGCCTTTTCTTTGACCTCTTCTTTCTGTTCATGTGTATTTGCTGTCTCTTAGCCCAGACTTCCCGTGTCCTTTCCACCGGGCCTTTGAGAGGTCACAGGGTCTTGATGCTGTGGTCTTCATCTGCAGGTGTCTGACTTCCAGCAACTGCTGGCCTGTGCCAGGGTGCAGCTGAGCACTGGAGTGGAGTTTTCCTGTGGAGAGGAGCCATGCCTAGAGTGGGATGGGCCATTGTTCATG"},
    {"Mouse","CGCAATTTTTACTTAATTCTTTTTCTTTTAATTCATATATTTTTAATATGTTTACTATTAATGGTTATCATTCACCATTTAACTATTTGTTATTTTGACGTCATTTTTTTCTATTTCCTCTTTTTTCAATTCATGTTTATTTTCTGTATTTTTGTTAAGTTTTCACAAGTCTAATATAATTGTCCTTTGAGAGGTTATTTGGTCTATATTTTTTTTTCTTCATCTGTATTTTTATGATTTCATTTAATTGATTTTCATTGACAGGGTTCTGCTGTGTTCTGGATTGTATTTTTCTTGTGGAGAGGAACTATTTCTTGAGTGGGATGTACCTTTGTTCTTG"},
    {"Unknown","CGCATTTTTGCCGGTTTTCCTTTGCTGTTTATTCATTTATTTTAAACGATATTTATATCATCGGGTTTCATTCACTATTTTTCTTTTCGATAAATTTTTGTCAGCATTTTCTTTTACCTCTTCTTTCTGTTTATGTTAATTTTCTGTTTCTTAACCCAGTCTTCTCGATTCTTATCTACCGGACCTATTATAGGTCACAGGGTCTTGATGCTTTGGTTTTCATCTGCAAGAGTCTGACTTCCTGCTAATGCTGTTCTGTGTCAGGGTGCATCTGAGCACTGATGTGGAGTTTTCTTGTGGATATGAGCCATTCATAGTGTGGGATGTGCCATAGTTCATG"}};


/*
 //  Part 1 - Compare two sequences to each other
 */

float calcSimilarity(string sequenceOne, string sequenceTwo) {
    if (sequenceOne.length() != sequenceTwo.length()) {
        return 0;
    } else {
        int i = 0;
        float hamming = 0;
        for(auto & letter : sequenceOne) {
            if (letter != sequenceTwo[i]) {
                hamming++;
            }
            i++;
        }
        return (sequenceTwo.length() - hamming)/sequenceTwo.length();
    }
}

/*
 //  Part 2 – Find locations of matches between genome and sequence
 */

void listSequencePositions(string genomeSequence, string genomeName, string seq){
    string replacement = "---------------------------------------------------------";
    replacement = replacement.substr(1,seq.length());
    cout << genomeName << " match locations:";
    while (genomeSequence.find(seq)!=string::npos){
        cout << genomeSequence.find(seq)+1 << " ";
        genomeSequence.replace(genomeSequence.find(seq),seq.length(),replacement);
    }
    cout << endl;
}

/*
 //  Part 3 – Find best match between genome and sequence
 */

float compareDNA(string genome, string seq){
    float score = 0;
    while (genome.length() >= seq.length()) {
        string sub = genome.substr(0,seq.length());
        float score_at_pos = calcSimilarity(sub, seq);
        if (score_at_pos > score) {
            score = score_at_pos;
        }
        genome.erase(0, 1);
    }
    return score;
}

void compare3Genomes(string genome1, string name1, string genome2, string name2, string genome3, string name3, string seq){
    float scores[3] = {};
    
    string items[3][2] = {{name1, genome1},{name2,genome2},{name3,genome3}};
    
    int i = 0;
    float result = 0;
    for(auto & item : items){
        float score = compareDNA(item[1], seq);
        scores[i] = score;
        if(score > result){
            result = score;
        }
        i++;
    }
    
    int t = 0;
    
    for(float score : scores){
        if (score == result) {
            cout << "Best match: " << items[t][0] << endl;
        }
        t++;
    }
}
