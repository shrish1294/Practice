class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        mapper = defaultdict(list)

        for w in strs:
            words = [0]*26
            for ch in w:
                words[ord(ch) - 97] += 1
            mapper[tuple(words)].append(w)
        
        answer = []

        for k, v in mapper.items():
            answer.append(v)
        
        return answer
        