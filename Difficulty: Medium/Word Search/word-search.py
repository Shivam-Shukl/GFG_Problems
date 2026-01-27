
class Solution:
    def solve(self, mat, word, i, j, idx, visited):
        n = len(mat)
        m = len(mat[0])
        s = len(word)

        if idx == s:
            return True

        ch = word[idx]

        # right
        if j + 1 < m and mat[i][j + 1] == ch and visited[i][j + 1] == 0:
            visited[i][j + 1] = 1
            if self.solve(mat, word, i, j + 1, idx + 1, visited):
                return True
            visited[i][j + 1] = 0

        # left
        if j - 1 >= 0 and mat[i][j - 1] == ch and visited[i][j - 1] == 0:
            visited[i][j - 1] = 1
            if self.solve(mat, word, i, j - 1, idx + 1, visited):
                return True
            visited[i][j - 1] = 0

        # down
        if i + 1 < n and mat[i + 1][j] == ch and visited[i + 1][j] == 0:
            visited[i + 1][j] = 1
            if self.solve(mat, word, i + 1, j, idx + 1, visited):
                return True
            visited[i + 1][j] = 0

        # up
        if i - 1 >= 0 and mat[i - 1][j] == ch and visited[i - 1][j] == 0:
            visited[i - 1][j] = 1
            if self.solve(mat, word, i - 1, j, idx + 1, visited):
                return True
            visited[i - 1][j] = 0

        return False

    def isWordExist(self, mat, word):
        n = len(mat)
        m = len(mat[0])

        for i in range(n):
            for j in range(m):
                if mat[i][j] == word[0]:
                    visited = [[0]*m for _ in range(n)]
                    visited[i][j] = 1
                    if self.solve(mat, word, i, j, 1, visited):
                        return True

        return False
