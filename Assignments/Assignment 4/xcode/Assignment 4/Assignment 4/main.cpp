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

int main() {
    
    //  Part 1
    
    string sequenceone, sequencetwo;
    while (sequenceone != "*" && sequencetwo != "*") {
        cout << "Enter sequence 1:" << endl;
        cin >> sequenceone;
        
        if (sequenceone == "*")
            break;
        
        cout << "Enter sequence 2:" << endl;
        cin >> sequencetwo;
        
        if (sequencetwo == "*")
            break;
        
        cout << "Similarity: " << calcSimilarity(sequenceone, sequencetwo) << endl;
    }
    
    //  Part 2
    
    string part2;
    while (part2 != "*") {
        cout << "Enter sequence:" << endl;
        cin >> part2;
        if (part2 == "*")
            break;
        
        for(auto & row : DNA) {
            string dna_title = row[0];
            string dna_sequence = row[1];
            listSequencePositions(dna_sequence, dna_title, part2);
        }
    }
    
    //  Part 3
    
    string part3;
    while (part3 != "*") {
        cout << "Enter user sequence:" << endl;
        cin >> part3;

        if (part3 == "*")
            break;

        compare3Genomes(DNA[0][1], DNA[0][0], DNA[1][1], DNA[1][0], DNA[2][1], DNA[2][0], part3);
    }
    
    return 0;
}

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
    for(auto & item : items){
        float score = compareDNA(item[1], seq);
        scores[i] = score;
        i++;
    }
    float result = std::max_element(scores,scores+3)[0];
    
    int t = 0;
    
    for(float score : scores){
        if (score == result) {
            cout << "Best match: " << items[t][0] << endl;
        }
        t++;
    }
}




