class Solution {
	public:
		    string repeatLimitedString(string s, int repeatLimit) {
			            int freq[26] = {};
				            for (char c : s) freq[c - 'a']++;

					            priority_queue<pair<char, int>> pq;
						            for (int i = 0; i < 26; ++i) {
								                if (freq[i]) pq.push({'a' + i, freq[i]});
										        }

							            string res;
								            while (!pq.empty()) {
										                auto [ch, cnt] = pq.top(); pq.pop();
												            int use = min(cnt, repeatLimit);
													                res.append(use, ch);
															            cnt -= use;

																                if (cnt > 0) {
																			                if (pq.empty()) break;
																					                auto [nextCh, nextCnt] = pq.top(); pq.pop();
																							                res += nextCh;
																									                nextCnt--;

																											                if (nextCnt > 0) pq.push({nextCh, nextCnt});
																													                pq.push({ch, cnt});
																															            }
																		        }
									            return res;
										        }
};
