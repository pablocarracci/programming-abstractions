/* File: OnlyConnect.cpp */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
using namespace std;

/** Returns true if the character is a vowel, false otherwise. */
bool isVowel(char ch) {
    return stringContains("AEIOUY", toupper(ch));
}

/** Returns true if the character is a consonant, false otherwise. */
bool isConsonant(char ch) {
    return !isVowel(ch) && !isdigit(ch) && !ispunct(ch) && !isspace(ch);
}

string onlyConnectize(string phrase) {
    if (phrase.empty()) {
        return "";
    }

    char ch = toupper(phrase[0]);
    if (isConsonant(ch)) {
        return ch + onlyConnectize(phrase.erase(0, 1));
    }
    return onlyConnectize(phrase.erase(0, 1));
}


/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

STUDENT_TEST("Handles empty and blank inputs.") {
    EXPECT_EQUAL(onlyConnectize(""), "");
    EXPECT_EQUAL(onlyConnectize("     "), "");
}

STUDENT_TEST("Handles input with leading and trailing blanks.") {
    EXPECT_EQUAL(onlyConnectize("   Text   "), "TXT");
    EXPECT_EQUAL(onlyConnectize("   AEIOUY   "), "");
}

STUDENT_TEST("Handles mixed case and characters.") {
    EXPECT_EQUAL(onlyConnectize("1337@H4CK3RS.X"), "HCKRSX");
    EXPECT_EQUAL(onlyConnectize("!Is,tHiS-.aN*InPuT!?"), "STHSNNPT");
}

/* Some general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */
