//
//  Name            John Keller
//  Recitation TA   Jason Zietz
//  Assignment #    4
//

#include "Assignment4.cpp"

using namespace std;

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
