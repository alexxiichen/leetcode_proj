/*
 * @lc app=leetcode.cn id=3 lang=golang
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.96%)
 * Total Accepted:    103.2K
 * Total Submissions: 356.4K
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 * 示例 1:
 *
 * 输入: "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *
 * 示例 2:
 *
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *
 */

package main

func lengthOfLongestSubstring(s string) int {
	ans := 1
	for i := 0; i < len(s); i++ {
		for j := i + 1; j <= len(s); j++ {
			if allUnique(s, i, j) {
				ans = max(ans, j-i)
			}
		}
	}
	return ans
}

func allUnique(s string, start int, end int) bool {
	mp := make(map[byte]byte)
	for index := start; index < end; index++ {
		if _, ok := mp[s[index]]; ok {
			return false
		}
		mp[s[index]] = s[index]
	}
	return true
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
