class TrieNode:
    def __init__(self):
        self.children=[None for _ in range(26)]
        self.isEnd = False
class Solution:
    def insertAtTrie(self, word):
        curr = self.root
        for ch in word:
            if curr.children[ ord(ch) - ord('a')] is None:
                curr.children[ ord(ch) - ord('a')] = TrieNode()
            curr = curr.children[ ord(ch) - ord('a')]
        curr.isEnd = True
    def search(self,word):
        curr = self.root
        re=""
        for ch in word:
            if curr.children[ord(ch) - ord('a')] is None:
                return word
            re += ch
            curr = curr.children[ord(ch) - ord('a')]
            if curr.isEnd:
                return re
        return word
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        self.root = TrieNode()
        for words in dictionary:
            self.insertAtTrie(words)
        arr = sentence.split(' ')
        ans =""
        for idx,word in enumerate(arr):
            ans += self.search(word)
            if idx<len(arr)-1:
                ans +=" "
        return ans