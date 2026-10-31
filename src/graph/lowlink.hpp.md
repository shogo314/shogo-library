---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/graph/tree.hpp
    title: "\u6728\u306E\u6C4E\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/grl-3-a.test.cpp
    title: test/aoj/grl/grl-3-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/grl-3-b.test.cpp
    title: test/aoj/grl/grl-3-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/graph/lowlink.test.cpp
    title: test/unittest/graph/lowlink.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/graph/biconnected-components.test.cpp
    title: test/yosupo/graph/biconnected-components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/graph/two-edge-connected-components.test.cpp
    title: test/yosupo/graph/two-edge-connected-components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "lowlink (\u95A2\u7BC0\u70B9\u3001\u6A4B\u3001\u4E8C\u91CD\u8FBA\
      \u9023\u7D50\u6210\u5206\u5206\u89E3\u3001\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\
      \u6210\u5206\u5206\u89E3\u3001Block-Cut Tree)"
    links: []
  bundledCode: "#line 2 \"src/graph/lowlink.hpp\"\n\n/**\n * @file lowlink.hpp\n *\
    \ @brief lowlink (\u95A2\u7BC0\u70B9\u3001\u6A4B\u3001\u4E8C\u91CD\u8FBA\u9023\
    \u7D50\u6210\u5206\u5206\u89E3\u3001\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\u3001Block-Cut Tree)\n */\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\n#line 2 \"src/graph/graph.hpp\"\n\n/**\n * @file\
    \ graph.hpp\n * @brief \u30B0\u30E9\u30D5\n */\n\n#line 9 \"src/graph/graph.hpp\"\
    \n#include <iostream>\n#line 11 \"src/graph/graph.hpp\"\n\n/**\n * @brief \u30B0\
    \u30E9\u30D5\u306E\u6C4E\u7528\u30AF\u30E9\u30B9\n *\n * @tparam Cost \u8FBA\u306E\
    \u30B3\u30B9\u30C8\u306E\u578B \u7701\u7565\u3057\u305F\u3089 long long (\u91CD\
    \u307F\u306E\u548C\u3084\u672A\u5230\u9054\u3092\u8868\u3059 max / 4 \u304C\u3042\
    \u3075\u308C\u306B\u304F\u3044\u3088\u3046\u306B)\n */\ntemplate <typename Cost\
    \ = long long>\nclass Graph {\n   public:\n    /**\n     * @brief \u6709\u5411\
    \u8FBA\u306E\u69CB\u9020\u4F53\n     *\n     * operator long long()\u3092\u5B9A\
    \u7FA9\u3057\u3066\u3044\u308B\u306E\u3067\u3001\u6574\u6570\u578B\u306B\u30AD\
    \u30E3\u30B9\u30C8\u3059\u308B\u3068\u52DD\u624B\u306Bdst\u306B\u306A\u308B\n\
    \     * \u4F8B\u3048\u3070\u3001\n     * for (auto& e : g[v]) \u3092\u3059\u308B\
    \u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\u304C\u5217\u6319\u3055\u308C\u308B\
    \u304C\u3001\n     * for (long long dst : g[v]) \u3068\u3059\u308B\u3068\u3001\
    v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u884C\u304D\u5148\u304C\u5217\u6319\u3055\
    \u308C\u308B\n     */\n    struct Edge {\n        long long src = -1;  //!< \u59CB\
    \u70B9\n        long long dst = -1;  //!< \u7D42\u70B9\n        Cost cost = {};\
    \      //!< \u30B3\u30B9\u30C8\n        long long id = -1;   //!< \u8FBA\u306E\
    \u756A\u53F7(\u8FFD\u52A0\u3055\u308C\u305F\u9806\u3001\u7121\u5411\u8FBA\u306E\
    \u5834\u5408\u306Fid\u304C\u540C\u3058\u3067\u65B9\u5411\u304C\u9006\u306E\u3082\
    \u306E\u304C2\u3064\u5B58\u5728\u3059\u308B)\n        Edge() = default;\n    \
    \    Edge(long long src, long long dst, Cost cost = 1, long long id = -1) : src(src),\
    \ dst(dst), cost(cost), id(id) {}\n        operator long long() const { return\
    \ dst; }\n    };\n\n    long long n;                       //!< \u9802\u70B9\u6570\
    \n    long long m;                       //!< \u8FBA\u6570\n    std::vector<std::vector<Edge>>\
    \ g;  //!< \u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u8868\u73FE\n\
    \n    /**\n     * @brief \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n     */\n    Graph() : n(0), m(0), g(0) {}\n    /**\n    \
    \ * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param n \u9802\u70B9\
    \u6570\n     */\n    explicit Graph(long long n) : n(n), m(0), g(n) {}\n    /**\n\
    \     * @brief \u9802\u70B9\u6570\n     */\n    long long size() const { return\
    \ n; }\n    /**\n     * @brief \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\
    \n     * @param u \u59CB\u70B9\n     * @param v \u7D42\u70B9\n     * @param w\
    \ \u30B3\u30B9\u30C8 \u7701\u7565\u3057\u305F\u30891\n     */\n    void add_edge(long\
    \ long u, long long v, Cost w = 1) {\n        assert(0 <= u && u < n && 0 <= v\
    \ && v < n);\n        g[u].push_back({u, v, w, m});\n        g[v].push_back({v,\
    \ u, w, m++});\n    }\n    /**\n     * @brief \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\
    \u3059\u308B\n     * @param u \u59CB\u70B9\n     * @param v \u7D42\u70B9\n   \
    \  * @param w \u30B3\u30B9\u30C8 \u7701\u7565\u3057\u305F\u30891\n     */\n  \
    \  void add_directed_edge(long long u, long long v, Cost w = 1) {\n        assert(0\
    \ <= u && u < n && 0 <= v && v < n);\n        g[u].push_back({u, v, w, m++});\n\
    \    }\n    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\u6A19\u6E96\u5165\
    \u529B\u304B\u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\u3059\u308B\n   \
    \  * @param m \u8FBA\u306E\u6570\n     * @param padding \u9802\u70B9\u756A\u53F7\
    \u3092\u5165\u529B\u304B\u3089\u3044\u304F\u3064\u305A\u3089\u3059\u304B \u7701\
    \u7565\u3057\u305F\u3089-1\n     * @param weighted \u8FBA\u306E\u91CD\u307F\u304C\
    \u5165\u529B\u3055\u308C\u308B\u304B \u7701\u7565\u3057\u305F\u3089false\u3068\
    \u306A\u308A\u3001\u91CD\u307F1\u3067\u8FBA\u304C\u8FFD\u52A0\u3055\u308C\u308B\
    \n     * @param directed \u6709\u5411\u30B0\u30E9\u30D5\u304B\u3069\u3046\u304B\
    \ \u7701\u7565\u3057\u305F\u3089false\n     */\n    void read(long long m, long\
    \ long padding = -1, bool weighted = false, bool directed = false) {\n       \
    \ for (long long i = 0; i < m; i++) {\n            long long u, v;\n         \
    \   std::cin >> u >> v;\n            u += padding, v += padding;\n           \
    \ Cost c(1);\n            if (weighted)\n                std::cin >> c;\n    \
    \        if (directed)\n                add_directed_edge(u, v, c);\n        \
    \    else\n                add_edge(u, v, c);\n        }\n    }\n    /**\n   \
    \  * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\u308B\u8FBA\u3092\u5217\
    \u6319\u3059\u308B\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return std::vector<Edge>&\
    \ v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<Edge>&\
    \ operator[](long long v) {\n        return g[v];\n    }\n    /**\n     * @brief\
    \ \u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\u308B\u8FBA\u3092\u5217\u6319\u3059\
    \u308B\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return const std::vector<Edge>&\
    \ v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u30EA\u30B9\u30C8\n     */\n    const\
    \ std::vector<Edge>& operator[](long long v) const {\n        return g[v];\n \
    \   }\n    /**\n     * @brief \u8FBA\u306E\u30EA\u30B9\u30C8\n     * @return std::vector<Edge>\
    \ \u8FBA\u306E\u30EA\u30B9\u30C8(id\u306E\u6607\u9806)\n     *\n     * \u7121\u5411\
    \u8FBA\u306F\u4EE3\u8868\u3057\u30661\u3064\u3060\u3051\u683C\u7D0D\u3055\u308C\
    \u308B\u3002\u305D\u306E src \u3068 dst \u306E\u5411\u304D\u306F\u898F\u5B9A\u3057\
    \u306A\u3044\n     * \u6709\u5411\u8FBA\u306F\u8FFD\u52A0\u3057\u305F\u3068\u304D\
    \u306E\u5411\u304D\u306E\u307E\u307E\u683C\u7D0D\u3055\u308C\u308B\n     */\n\
    \    std::vector<Edge> edges() const {\n        std::vector<Edge> res(m);\n  \
    \      for (long long i = 0; i < n; i++) {\n            for (auto& e : g[i]) {\n\
    \                res[e.id] = e;\n            }\n        }\n        return res;\n\
    \    }\n};\n#line 2 \"src/graph/tree.hpp\"\n\n/**\n * @file tree.hpp\n * @brief\
    \ \u6728\u306E\u6C4E\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\n#line 10\
    \ \"src/graph/tree.hpp\"\n#include <stack>\n#include <type_traits>\n#include <utility>\n\
    #line 14 \"src/graph/tree.hpp\"\n\n#line 16 \"src/graph/tree.hpp\"\n\ntemplate\
    \ <typename>\nclass RootedTree;\ntemplate <typename>\nclass DoublingClimbTree;\n\
    \n/**\n * @brief \u6839\u306A\u3057\u6728\n *\n * @tparam Cost = long long \u8FBA\
    \u306E\u91CD\u307F\n *\n * Graph<Cost>\u3092\u7D99\u627F\u3057\u3001\u3059\u3079\
    \u3066\u7121\u5411\u8FBA\u3067\u8868\u3059\n */\ntemplate <typename Cost = long\
    \ long>\nstruct Tree : private Graph<Cost> {\n    // Graph<Cost>* g = new Tree<Cost>();\
    \ \u304C\u3067\u304D\u3066\u3057\u307E\u3046\u3068\u3001delete\u6642\u306B\u30E1\
    \u30E2\u30EA\u30EA\u30FC\u30AF\u304C\u767A\u751F\n    // \u56DE\u907F\u3059\u308B\
    \u305F\u3081private\u7D99\u627F\u306B\u3057\u3066\u3001\u516C\u958B\u3059\u308B\
    \u30E1\u30F3\u30D0\u3092using\u5BA3\u8A00\u3059\u308B\n    // add_directed_edge\
    \ \u306F\u6728\u3067\u306A\u304F\u306A\u308B\u306E\u3067\u516C\u958B\u3057\u306A\
    \u3044 (read \u306F Tree::read \u3067\u96A0\u3059)\n    using Edge = typename\
    \ Graph<Cost>::Edge;\n    using Graph<Cost>::n;\n    using Graph<Cost>::size;\n\
    \    using Graph<Cost>::m;\n    using Graph<Cost>::g;\n    using Graph<Cost>::Graph;\n\
    \    using Graph<Cost>::add_edge;\n    using Graph<Cost>::operator[];\n    using\
    \ Graph<Cost>::edges;\n\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n     *\n     * @param n \u30CE\u30FC\u30C9\u6570\n     */\n    explicit\
    \ Tree(long long n = 0) : Graph<Cost>(n) {}\n\n    /**\n     * @brief Graph \u3068\
    \u3057\u3066\u898B\u308B\n     *\n     * Graph \u3092\u53D7\u3051\u53D6\u308B\u95A2\
    \u6570 (shortest_path \u306A\u3069) \u306B\u6E21\u3059\u3068\u304D\u306B\u4F7F\
    \u3046\n     * @return const Graph<Cost>& \u3053\u306E\u6728\u3092\u8868\u3059\
    \u30B0\u30E9\u30D5\n     */\n    const Graph<Cost>& graph() const { return *this;\
    \ }\n\n    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\u6A19\u6E96\u5165\
    \u529B\u304B\u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\u3059\u308B\n   \
    \  * @param padding  = -1 \u9802\u70B9\u756A\u53F7\u3092\u5165\u529B\u304B\u3089\
    \u3044\u304F\u3064\u305A\u3089\u3059\u304B\n     * @param weighted = false \u8FBA\
    \u306E\u91CD\u307F\u304C\u5165\u529B\u3055\u308C\u308B\u304B\n     */\n    void\
    \ read(long long padding = -1, bool weighted = false) {\n        Graph<Cost>::read(this->n\
    \ - 1, padding, weighted, false);\n    }\n\n    /**\n     * @brief \u6839\u4ED8\
    \u304D\u6728\u306B\u3059\u308B\n     *\n     * @param root \u6839\n     * @return\
    \ RootedTree<Cost> \u6839\u4ED8\u304D\u6728\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n     */\n    [[nodiscard]]\n    RootedTree<Cost> set_root(long long root)\
    \ const& {\n        return RootedTree<Cost>(*this, root);\n    }\n    /**\n  \
    \   * @brief \u6839\u4ED8\u304D\u6728\u306B\u3057\u3066\u8FD4\u3059\n     *\n\
    \     * @param root \u6839\n     * @return RootedTree<Cost> \u6839\u4ED8\u304D\
    \u6728\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n\
    \    RootedTree<Cost> set_root(long long root) && {\n        return RootedTree<Cost>(std::move(*this),\
    \ root);\n    }\n\n    /**\n     * @brief \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\
    \u4F7F\u3048\u308B\u6839\u4ED8\u304D\u6728\u3092\u8FD4\u3059\n     *\n     * @param\
    \ root \u6839\n     * @return DoublingClimbTree<Cost> \u30C0\u30D6\u30EA\u30F3\
    \u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost> build_lca(long\
    \ long root) const& {\n        RootedTree rooted_tree(*this, root);\n        return\
    \ DoublingClimbTree<Cost>(std::move(rooted_tree));\n    }\n    /**\n     * @brief\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\u6839\u4ED8\u304D\u6728\
    \u3092\u8FD4\u3059\n     *\n     * @param root \u6839\n     * @return DoublingClimbTree<Cost>\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost>\
    \ build_lca(long long root) && {\n        RootedTree rooted_tree(std::move(*this),\
    \ root);\n        return DoublingClimbTree<Cost>(std::move(rooted_tree));\n  \
    \  }\n};\n\n/**\n * @brief \u6839\u4ED8\u304D\u6728\n *\n * @tparam Cost = long\
    \ long \u8FBA\u306E\u30B3\u30B9\u30C8\n */\ntemplate <typename Cost = long long>\n\
    class RootedTree : private Tree<Cost> {\n   public:\n    using Edge = typename\
    \ Tree<Cost>::Edge;\n    using Tree<Cost>::n;\n    using Tree<Cost>::size;\n \
    \   using Tree<Cost>::m;\n    using Tree<Cost>::g;\n    using Tree<Cost>::operator[];\n\
    \    using Tree<Cost>::edges;\n    using Tree<Cost>::graph;\n\n    long long root;\
    \                                           //!< \u6839\n    std::vector<Edge>\
    \ par;                                    //!< \u89AA\u3078\u5411\u304B\u3046\u8FBA\
    \n    std::vector<std::vector<Edge>> child;                     //!< \u5B50\u3078\
    \u5411\u304B\u3046\u8FBA\u306E\u30EA\u30B9\u30C8\n    std::vector<Cost> depth;\
    \                                  //!< \u6DF1\u3055\u306E\u30EA\u30B9\u30C8\n\
    \    std::vector<Cost> height;                                 //!< \u90E8\u5206\
    \u6728\u306E\u9AD8\u3055\u306E\u30EA\u30B9\u30C8\n    std::vector<long long> unweighted_depth;\
    \                  //!< \u91CD\u307F\u306A\u3057\u306E\u6DF1\u3055\u306E\u30EA\
    \u30B9\u30C8\n    std::vector<long long> unweighted_height;                 //!<\
    \ \u91CD\u307F\u306A\u3057\u306E\u90E8\u5206\u6728\u306E\u9AD8\u3055\u306E\u30EA\
    \u30B9\u30C8\n    std::vector<long long> sz;                                //!<\
    \ \u90E8\u5206\u6728\u306E\u9802\u70B9\u6570\u306E\u30EA\u30B9\u30C8\n    std::vector<long\
    \ long> preorder;                          //!< \u5148\u884C\u9806\u5DE1\u56DE\
    \n    std::vector<long long> postorder;                         //!< \u5F8C\u884C\
    \u9806\u5DE1\u56DE\n    std::vector<std::pair<long long, long long>> euler_tour;\
    \  //!< \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC DFS\u4E2D\u306B\u3068\u304A\
    \u3063\u305F\u9802\u70B9\u306E(\u9802\u70B9\u756A\u53F7,\u305D\u306E\u9802\u70B9\
    \u3092\u901A\u3063\u305F\u56DE\u6570)\u306E\u30EA\u30B9\u30C8\n\n    RootedTree()\
    \ = delete;\n\n    /**\n     * @brief \u89AA\u306E\u9802\u70B9\u306E\u30EA\u30B9\
    \u30C8\u304B\u3089\u6839\u304C0\u306E\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\
    \u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @tparam\
    \ T \u9802\u70B9\u756A\u53F7\u306E\u6574\u6570\u578B (long long \u3084 int)\n\
    \     * @param par_ \u9802\u70B90\u4EE5\u5916\u306E\u89AA\u306E\u9802\u70B9\u306E\
    \u30EA\u30B9\u30C8\n     * @param padding = -1 par\u306E\u9802\u70B9\u756A\u53F7\
    \u3092\u3044\u304F\u3064\u305A\u3089\u3059\u304B\n     */\n    template <typename\
    \ T = long long>\n    explicit RootedTree(const std::vector<T>& par_, long long\
    \ padding = -1) : Tree<Cost>(par_.size() + 1), root(0) {\n        static_assert(std::is_integral_v<T>,\
    \ \"RootedTree: par_ must be a vector of integers\");\n        for (long long\
    \ i = 0; i < static_cast<long long>(par_.size()); i++) {\n            this->add_edge(i\
    \ + 1, par_[i] + padding);\n        }\n        build();\n    }\n    /**\n    \
    \ * @brief Tree\u304B\u3089\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\
    \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u30B3\u30D4\u30FC)\n     *\n     *\
    \ @param tree Tree \u9802\u70B9\u65701\u4EE5\u4E0A\n     * @param root \u6839\n\
    \     */\n    RootedTree(const Tree<Cost>& tree, long long root) : Tree<Cost>(tree),\
    \ root(root) {\n        build();\n    }\n    /**\n     * @brief Tree\u304B\u3089\
    \u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF(\u30E0\u30FC\u30D6)\n     *\n     * @param tree Tree\n    \
    \ * @param root \u6839\n     */\n    RootedTree(Tree<Cost>&& tree, long long root)\
    \ : Tree<Cost>(std::move(tree)), root(root) {\n        build();\n    }\n\n   \
    \ /**\n     * @brief \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\
    \u6839\u4ED8\u304D\u6728\u3092\u5F97\u308B\n     *\n     * @return DoublingClimbTree<Cost>\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost>\
    \ build_lca() const& {\n        return DoublingClimbTree<Cost>(*this);\n    }\n\
    \n    /**\n     * @brief \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\
    \u6839\u4ED8\u304D\u6728\u3092\u5F97\u308B\n     *\n     * @return DoublingClimbTree<Cost>\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost>\
    \ build_lca() && {\n        return DoublingClimbTree<Cost>(std::move(*this));\n\
    \    }\n\n   private:\n    void build() {\n        long long n = this->n;\n  \
    \      assert(n > 0);\n        assert(0 <= root && root < n);\n        par.resize(n);\n\
    \        par[root] = {root, -1, 0, -1};\n        child.resize(n);\n        depth.resize(n);\n\
    \        unweighted_depth.resize(n);\n        height.resize(n);\n        unweighted_height.resize(n);\n\
    \        sz.resize(n);\n        std::vector<int> iter(n);\n        std::stack<std::pair<int,\
    \ int>> stk;\n        stk.emplace(root, 0);\n        while (!stk.empty()) {\n\
    \            auto [u, cnt] = stk.top();\n            stk.pop();\n            euler_tour.emplace_back(u,\
    \ cnt);\n            if (iter[u] == 0) preorder.push_back(u);\n            while\
    \ (iter[u] < static_cast<int>(this->g[u].size()) && this->g[u][iter[u]].dst ==\
    \ par[u]) iter[u]++;\n            if (iter[u] == static_cast<int>(this->g[u].size()))\
    \ {\n                postorder.push_back(u);\n                sz[u] = 1;\n   \
    \             height[u] = 0;\n                unweighted_height[u] = 0;\n    \
    \            for (auto& e : child[u]) {\n                    sz[u] += sz[e.dst];\n\
    \                    if (height[u] < height[e.dst] + e.cost) {\n             \
    \           height[u] = height[e.dst] + e.cost;\n                    }\n     \
    \               if (unweighted_height[u] < unweighted_height[e.dst] + 1) {\n \
    \                       unweighted_height[u] = unweighted_height[e.dst] + 1;\n\
    \                    }\n                }\n            } else {\n            \
    \    auto& e = this->g[u][iter[u]++];\n                par[e.dst] = {e.dst, u,\
    \ e.cost, e.id};\n                child[u].push_back(e);\n                depth[e.dst]\
    \ = depth[u] + e.cost;\n                unweighted_depth[e.dst] = unweighted_depth[u]\
    \ + 1;\n                stk.emplace(u, cnt + 1);\n                stk.emplace(e.dst,\
    \ 0);\n            }\n        }\n    }\n};\n\n/**\n * @brief \u89AA\u9802\u70B9\
    \u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\n *\n * @tparam\
    \ Cost = long long \u8FBA\u306E\u91CD\u307F(\u6CE8: hop\u3067\u306F\u6839\u306E\
    \u91CD\u307F\u306F\u8003\u3048\u306A\u3044)\n */\ntemplate <typename Cost = long\
    \ long>\nclass DoublingClimbTree : private RootedTree<Cost> {\n   public:\n  \
    \  using Edge = typename RootedTree<Cost>::Edge;\n    using RootedTree<Cost>::n;\n\
    \    using RootedTree<Cost>::size;\n    using RootedTree<Cost>::m;\n    using\
    \ RootedTree<Cost>::g;\n    using RootedTree<Cost>::operator[];\n    using RootedTree<Cost>::edges;\n\
    \    using RootedTree<Cost>::graph;\n    using RootedTree<Cost>::root;\n    using\
    \ RootedTree<Cost>::par;\n    using RootedTree<Cost>::child;\n    using RootedTree<Cost>::depth;\n\
    \    using RootedTree<Cost>::height;\n    using RootedTree<Cost>::unweighted_depth;\n\
    \    using RootedTree<Cost>::unweighted_height;\n    using RootedTree<Cost>::sz;\n\
    \    using RootedTree<Cost>::preorder;\n    using RootedTree<Cost>::postorder;\n\
    \    using RootedTree<Cost>::euler_tour;\n\n    long long h;                 \
    \                      //!< \u30C0\u30D6\u30EA\u30F3\u30B0\u306E\u56DE\u6570\n\
    \    std::vector<std::vector<long long>> doubling_par;  //!< j\u304B\u3089(1<<i)\u9802\
    \u70B9\u767B\u3063\u305F\u9802\u70B9(\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    \u306F-1)\n\n    DoublingClimbTree() = delete;\n\n    /**\n     * @brief RootedTree\u304B\
    \u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u3092\
    \u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u30B3\u30D4\
    \u30FC)\n     *\n     * @param tree RootedTree\n     */\n    explicit DoublingClimbTree(const\
    \ RootedTree<Cost>& tree) : RootedTree<Cost>(tree) {\n        build();\n    }\n\
    \n    /**\n     * @brief RootedTree\u304B\u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\
    \u307F\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF(\u30E0\u30FC\u30D6)\n     *\n     * @param tree RootedTree\n\
    \     */\n    DoublingClimbTree(RootedTree<Cost>&& tree) : RootedTree<Cost>(std::move(tree))\
    \ {\n        build();\n    }\n\n    /**\n     * @brief \u89AA\u306E\u9802\u70B9\
    \u306E\u30EA\u30B9\u30C8\u304B\u3089\u6839\u304C0\u306E\u30C0\u30D6\u30EA\u30F3\
    \u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @tparam T \u9802\u70B9\u756A\
    \u53F7\u306E\u6574\u6570\u578B (long long \u3084 int)\n     * @param par_ \u9802\
    \u70B90\u4EE5\u5916\u306E\u89AA\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\n  \
    \   * @param padding = -1 par\u306E\u9802\u70B9\u756A\u53F7\u3092\u3044\u304F\u3064\
    \u305A\u3089\u3059\u304B\n     */\n    template <typename T = long long>\n   \
    \ explicit DoublingClimbTree(const std::vector<T>& par_, long long padding = -1)\
    \ : RootedTree<Cost>(par_, padding) {\n        build();\n    }\n    /**\n    \
    \ * @brief Tree\u304B\u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\
    \u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF(\u30B3\u30D4\u30FC)\n     *\n     * @param tree Tree\n     * @param root\
    \ \u6839\n     */\n    DoublingClimbTree(const Tree<Cost>& tree, long long root)\
    \ : RootedTree<Cost>(tree, root) {\n        build();\n    }\n    /**\n     * @brief\
    \ Tree\u304B\u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\
    \u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    (\u30E0\u30FC\u30D6)\n     *\n     * @param tree Tree\n     * @param root \u6839\
    \n     */\n    DoublingClimbTree(Tree<Cost>&& tree, long long root) : RootedTree<Cost>(std::move(tree),\
    \ root) {\n        build();\n    }\n\n    /**\n     * @brief \u9802\u70B9u\u304B\
    \u3089k\u56DE\u3092\u6839\u306E\u65B9\u5411\u306B\u9061\u3063\u305F\u9802\u70B9\
    \n     *\n     * @param u \u5143\u306E\u9802\u70B9\n     * @param k \u767B\u308B\
    \u6BB5\u6570\n     * @return long long k\u56DE\u767B\u3063\u305F\u9802\u70B9 (\u5B58\
    \u5728\u3057\u306A\u3051\u308C\u3070 -1)\n     */\n    long long hop(long long\
    \ u, long long k) const {\n        assert(0 <= u && u < this->n && k >= 0);\n\
    \        if (k > this->unweighted_depth[u]) return -1;\n        for (long long\
    \ i = 0; i < h; i++) {\n            if (k >> i & 1) u = doubling_par[i][u];\n\
    \            if (u == -1) return -1;\n        }\n        return u;\n    }\n\n\
    \    /**\n     * @brief \u6700\u5C0F\u5171\u901A\u7956\u5148\n     *\n     * @param\
    \ u \u9802\u70B91\n     * @param v \u9802\u70B92\n     * @return long long LCA\u306E\
    \u9802\u70B9\u756A\u53F7\n     */\n    long long lca(long long u, long long v)\
    \ const {\n        assert(0 <= u && u < this->n && 0 <= v && v < this->n);\n \
    \       if (this->unweighted_depth[u] > this->unweighted_depth[v]) std::swap(u,\
    \ v);\n        v = hop(v, this->unweighted_depth[v] - this->unweighted_depth[u]);\n\
    \        if (u == v) return u;\n        for (long long i = h - 1; i >= 0; i--)\
    \ {\n            long long nu = doubling_par[i][u];\n            long long nv\
    \ = doubling_par[i][v];\n            if (nu == -1) continue;\n            if (nu\
    \ != nv) {\n                u = nu;\n                v = nv;\n            }\n\
    \        }\n        return this->par[u];\n    }\n\n    /**\n     * @brief \u9802\
    \u70B9\u9593\u8DDD\u96E2(\u91CD\u307F\u4ED8\u304D)\n     *\n     * @param u \u9802\
    \u70B91\n     * @param v \u9802\u70B92\n     * @return Cost u\u3068v\u9593\u306E\
    \u6700\u77ED\u7D4C\u8DEF\u306E\u8FBA\u306E\u91CD\u307F\u306E\u548C\n     */\n\
    \    Cost dist(long long u, long long v) const {\n        assert(0 <= u && u <\
    \ this->n && 0 <= v && v < this->n);\n        return this->depth[u] + this->depth[v]\
    \ - this->depth[lca(u, v)] * 2;\n    }\n\n   private:\n    void build() {\n  \
    \      long long n = this->n;\n        h = 1;\n        while ((1LL << h) < n)\
    \ h++;\n        doubling_par.assign(h, std::vector<long long>(n, -1));\n     \
    \   for (long long i = 0; i < n; i++) doubling_par[0][i] = this->par[i];\n   \
    \     for (long long i = 0; i < h - 1; i++) {\n            for (long long j =\
    \ 0; j < n; j++) {\n                if (doubling_par[i][j] != -1) {\n        \
    \            doubling_par[i + 1][j] = doubling_par[i][doubling_par[i][j]];\n \
    \               }\n            }\n        }\n    }\n};\n#line 14 \"src/graph/lowlink.hpp\"\
    \n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306E lowlink \u3092\u6C42\u3081\
    \u3001\u95A2\u7BC0\u70B9\u30FB\u6A4B\u30FB\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\
    \u5206\u30FB\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u3092\u6C42\u3081\
    \u308B\n *\n * DFS \u3092\u518D\u5E30\u3092\u4F7F\u308F\u305A\u306B\u884C\u3046\
    \u3002O(n + m)\n * \u591A\u91CD\u8FBA\u3068\u81EA\u5DF1\u30EB\u30FC\u30D7\u304C\
    \u3042\u3063\u3066\u3082\u3088\u3044 (\u89AA\u3078\u623B\u308B\u8FBA\u306F\u9802\
    \u70B9\u3067\u306F\u306A\u304F\u8FBA\u306E\u756A\u53F7\u3067\u533A\u5225\u3059\
    \u308B)\n * \u81EA\u5DF1\u30EB\u30FC\u30D7\u306F\u3069\u306E\u4E8C\u91CD\u9802\
    \u70B9\u9023\u7D50\u6210\u5206\u306E\u8FBA\u306B\u3082\u5165\u308C\u306A\u3044\
    \n * \u4F8B:\n * LowLink ll(g);\n * ll.articulation_points(); ll.bridges(); ll.two_edge_connected_groups();\n\
    \ * ll.two_vertex_connected_groups(); ll.block_cut_tree();\n *\n * @tparam Cost\
    \ \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B\n */\ntemplate <typename Cost = long\
    \ long>\nclass LowLink {\n    long long n;\n    std::vector<bool> art, bridge;\n\
    \    std::vector<long long> arts, bridge_ids;\n    std::vector<int> comp;\n  \
    \  std::vector<std::vector<long long>> groups;\n    std::vector<std::vector<long\
    \ long>> bc_groups, bc_edge_groups;\n    std::vector<long long> bc_edge_id;\n\n\
    \   public:\n    std::vector<long long> ord;  //!< DFS \u3067\u8A2A\u308C\u305F\
    \u9806\u756A\n    std::vector<long long> low;  //!< DFS \u6728\u306E\u5B50\u5B6B\
    \u304B\u3089\u3001\u6728\u306E\u8FBA\u3092\u9006\u306B\u305F\u3069\u3089\u305A\
    \u306B 1 \u672C\u306E\u5F8C\u9000\u8FBA\u3067\u884C\u3051\u308B\u9802\u70B9\u306E\
    \ ord \u306E\u6700\u5C0F\u5024\n\n    explicit LowLink(const Graph<Cost>& graph)\
    \ : n(graph.n), art(n), bridge(graph.m), comp(n, -1), bc_edge_id(graph.m, -1),\
    \ ord(n, -1), low(n) {\n        std::vector<int> parent(n, -1), parent_edge(n,\
    \ -1), iter(n, 0);\n        std::vector<long long> st;\n        // \u4E8C\u91CD\
    \u9802\u70B9\u9023\u7D50\u6210\u5206\u3092\u4F5C\u308B\u305F\u3081\u306B\u3001\
    \u901A\u3063\u305F\u8FBA (\u6728\u306E\u8FBA\u3068\u3001\u5B50\u5B6B\u304B\u3089\
    \u7956\u5148\u3078\u306E\u5F8C\u9000\u8FBA) \u3092\u7A4D\u3080\n        std::vector<long\
    \ long> edge_st, edge_src(graph.m), edge_dst(graph.m), last_block(n, -1);\n  \
    \      auto push_edge = [&](long long id, long long a, long long b) {\n      \
    \      edge_st.push_back(id);\n            edge_src[id] = a, edge_dst[id] = b;\n\
    \        };\n        long long k = 0;\n        for (long long root = 0; root <\
    \ n; root++) {\n            if (ord[root] != -1) continue;\n            int root_children\
    \ = 0;\n            ord[root] = low[root] = k++;\n            st.push_back(root);\n\
    \            while (!st.empty()) {\n                long long v = st.back();\n\
    \                if (iter[v] < static_cast<int>(graph[v].size())) {\n        \
    \            const auto& e = graph[v][iter[v]++];\n                    if (e.id\
    \ == parent_edge[v]) continue;\n                    long long u = e.dst;\n   \
    \                 if (ord[u] == -1) {\n                        parent[u] = v;\n\
    \                        parent_edge[u] = e.id;\n                        ord[u]\
    \ = low[u] = k++;\n                        st.push_back(u);\n                \
    \        push_edge(e.id, v, u);\n                    } else {\n              \
    \          low[v] = std::min(low[v], ord[u]);\n                        // \u5F8C\
    \u9000\u8FBA\u306F\u5B50\u5B6B\u306E\u5074\u304B\u3089\u898B\u305F\u3068\u304D\
    \u306B 1 \u56DE\u3060\u3051\u7A4D\u3080 (\u81EA\u5DF1\u30EB\u30FC\u30D7\u306F\u7A4D\
    \u307E\u306A\u3044)\n                        if (ord[u] < ord[v]) push_edge(e.id,\
    \ v, u);\n                    }\n                    continue;\n             \
    \   }\n                st.pop_back();\n                if (v == root) continue;\n\
    \                long long p = parent[v];\n                low[p] = std::min(low[p],\
    \ low[v]);\n                if (low[v] > ord[p]) bridge[parent_edge[v]] = true;\n\
    \                if (low[v] >= ord[p]) {\n                    // \u89AA\u3068\u306E\
    \u8FBA\u307E\u3067\u304C 1 \u3064\u306E\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\
    \u5206\n                    long long b = bc_groups.size();\n                \
    \    bc_groups.emplace_back();\n                    bc_edge_groups.emplace_back();\n\
    \                    while (true) {\n                        long long id = edge_st.back();\n\
    \                        edge_st.pop_back();\n                        bc_edge_id[id]\
    \ = b;\n                        bc_edge_groups[b].push_back(id);\n           \
    \             for (long long w : {edge_src[id], edge_dst[id]}) {\n           \
    \                 if (last_block[w] != b) last_block[w] = b, bc_groups[b].push_back(w);\n\
    \                        }\n                        if (id == parent_edge[v])\
    \ break;\n                    }\n                }\n                if (p == root)\n\
    \                    root_children++;\n                else if (low[v] >= ord[p])\n\
    \                    art[p] = true;\n            }\n            if (root_children\
    \ >= 2) art[root] = true;\n            // \u307B\u304B\u306E\u9802\u70B9\u3068\
    \u3064\u306A\u304C\u3063\u3066\u3044\u306A\u3044\u9802\u70B9\u306F\u3001\u305D\
    \u308C\u3060\u3051\u3067 1 \u3064\u306E\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\
    \u5206\n            if (root_children == 0) {\n                bc_groups.push_back({root});\n\
    \                bc_edge_groups.emplace_back();\n            }\n        }\n  \
    \      for (long long v = 0; v < n; v++) {\n            if (art[v]) arts.push_back(v);\n\
    \        }\n        for (long long id = 0; id < graph.m; id++) {\n           \
    \ if (bridge[id]) bridge_ids.push_back(id);\n        }\n        // \u6A4B\u3092\
    \u901A\u3089\u305A\u306B\u884C\u3051\u308B\u9802\u70B9\u3092\u307E\u3068\u3081\
    \u308B\n        for (long long s = 0; s < n; s++) {\n            if (comp[s] !=\
    \ -1) continue;\n            comp[s] = groups.size();\n            groups.push_back({s});\n\
    \            for (long long i = 0; i < static_cast<long long>(groups.back().size());\
    \ i++) {\n                long long v = groups.back()[i];\n                for\
    \ (const auto& e : graph[v]) {\n                    if (bridge[e.id] || comp[e.dst]\
    \ != -1) continue;\n                    comp[e.dst] = comp[s];\n             \
    \       groups.back().push_back(e.dst);\n                }\n            }\n  \
    \      }\n    }\n\n    /**\n     * @brief \u9802\u70B9\u6570\n     */\n    long\
    \ long size() const { return n; }\n\n    /**\n     * @brief v \u304C\u95A2\u7BC0\
    \u70B9 (\u53D6\u308A\u9664\u304F\u3068\u9023\u7D50\u6210\u5206\u304C\u5897\u3048\
    \u308B\u9802\u70B9) \u304B\n     */\n    bool is_articulation_point(long long\
    \ v) const {\n        assert(0 <= v && v < n);\n        return art[v];\n    }\n\
    \    /**\n     * @brief \u756A\u53F7 id \u306E\u8FBA\u304C\u6A4B (\u53D6\u308A\
    \u9664\u304F\u3068\u9023\u7D50\u6210\u5206\u304C\u5897\u3048\u308B\u8FBA) \u304B\
    \n     */\n    bool is_bridge(long long id) const {\n        assert(0 <= id &&\
    \ id < static_cast<long long>(bridge.size()));\n        return bridge[id];\n \
    \   }\n    /**\n     * @brief \u95A2\u7BC0\u70B9\u306E\u9802\u70B9\u756A\u53F7\
    \u306E\u6607\u9806\u306E\u30EA\u30B9\u30C8\n     */\n    const std::vector<long\
    \ long>& articulation_points() const { return arts; }\n    /**\n     * @brief\
    \ \u6A4B\u306E\u8FBA\u306E\u756A\u53F7\u306E\u6607\u9806\u306E\u30EA\u30B9\u30C8\
    \n     */\n    const std::vector<long long>& bridges() const { return bridge_ids;\
    \ }\n    /**\n     * @brief \u9802\u70B9 v \u304C\u5C5E\u3059\u308B\u4E8C\u91CD\
    \u8FBA\u9023\u7D50\u6210\u5206\u306E\u756A\u53F7\n     */\n    long long two_edge_connected_group_id(long\
    \ long v) const {\n        assert(0 <= v && v < n);\n        return comp[v];\n\
    \    }\n    /**\n     * @brief \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206 (\u6A4B\
    \u3092\u53D6\u308A\u9664\u3044\u305F\u3068\u304D\u306E\u9023\u7D50\u6210\u5206\
    ) \u3054\u3068\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\n     */\n    const std::vector<std::vector<long\
    \ long>>& two_edge_connected_groups() const { return groups; }\n\n    /**\n  \
    \   * @brief \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u3054\u3068\u306E\
    \u9802\u70B9\u306E\u30EA\u30B9\u30C8\n     * \u95A2\u7BC0\u70B9\u306F\u8907\u6570\
    \u306E\u6210\u5206\u306B\u5165\u308B\u3002\u307B\u304B\u306E\u9802\u70B9\u3068\
    \u3064\u306A\u304C\u3063\u3066\u3044\u306A\u3044\u9802\u70B9\u306F\u3001\u305D\
    \u308C\u3060\u3051\u3067 1 \u3064\u306E\u6210\u5206\u306B\u306A\u308B\n     */\n\
    \    const std::vector<std::vector<long long>>& two_vertex_connected_groups()\
    \ const { return bc_groups; }\n    /**\n     * @brief \u4E8C\u91CD\u9802\u70B9\
    \u9023\u7D50\u6210\u5206\u3054\u3068\u306E\u8FBA\u306E\u756A\u53F7\u306E\u30EA\
    \u30B9\u30C8 (two_vertex_connected_groups() \u3068\u540C\u3058\u9806)\n     *\
    \ \u81EA\u5DF1\u30EB\u30FC\u30D7\u4EE5\u5916\u306E\u8FBA\u306F\u3061\u3087\u3046\
    \u3069 1 \u3064\u306E\u6210\u5206\u306B\u5165\u308B\n     */\n    const std::vector<std::vector<long\
    \ long>>& two_vertex_connected_edge_groups() const { return bc_edge_groups; }\n\
    \    /**\n     * @brief \u756A\u53F7 id \u306E\u8FBA\u304C\u5C5E\u3059\u308B\u4E8C\
    \u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u306E\u756A\u53F7 (\u81EA\u5DF1\u30EB\
    \u30FC\u30D7\u306A\u3089 -1)\n     */\n    long long two_vertex_connected_group_id(long\
    \ long id) const {\n        assert(0 <= id && id < static_cast<long long>(bc_edge_id.size()));\n\
    \        return bc_edge_id[id];\n    }\n    /**\n     * @brief Block-Cut Tree\n\
    \     * \u9802\u70B9 0, ..., n - 1 \u306F\u5143\u306E\u9802\u70B9\u3001\u9802\u70B9\
    \ n + b \u306F\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206 b \u3067\u3001\u5143\
    \u306E\u9802\u70B9\u3068\u3001\u305D\u308C\u3092\u542B\u3080\u6210\u5206\u3092\
    \u8FBA\u3067\u7D50\u3076\n     * \u5143\u306E\u30B0\u30E9\u30D5\u304C\u9023\u7D50\
    \u306A\u3089\u6728\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070\u68EE\u306B\
    \u306A\u308B (\u68EE\u306E\u3068\u304D\u306F\u3001\u9023\u7D50\u3067\u3042\u308B\
    \u3053\u3068\u3092\u524D\u63D0\u3068\u3059\u308B\u6728\u306E\u95A2\u6570\u306B\
    \u306F\u6E21\u305B\u306A\u3044)\n     */\n    Tree<int> block_cut_tree() const\
    \ {\n        Tree<int> res(n + static_cast<long long>(bc_groups.size()));\n  \
    \      for (long long b = 0; b < static_cast<long long>(bc_groups.size()); b++)\
    \ {\n            for (long long v : bc_groups[b]) res.add_edge(v, n + b);\n  \
    \      }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file lowlink.hpp\n * @brief lowlink (\u95A2\u7BC0\
    \u70B9\u3001\u6A4B\u3001\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \u3001\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3\u3001Block-Cut\
    \ Tree)\n */\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\n\
    #include \"graph.hpp\"\n#include \"tree.hpp\"\n\n/**\n * @brief \u7121\u5411\u30B0\
    \u30E9\u30D5\u306E lowlink \u3092\u6C42\u3081\u3001\u95A2\u7BC0\u70B9\u30FB\u6A4B\
    \u30FB\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u30FB\u4E8C\u91CD\u9802\u70B9\
    \u9023\u7D50\u6210\u5206\u3092\u6C42\u3081\u308B\n *\n * DFS \u3092\u518D\u5E30\
    \u3092\u4F7F\u308F\u305A\u306B\u884C\u3046\u3002O(n + m)\n * \u591A\u91CD\u8FBA\
    \u3068\u81EA\u5DF1\u30EB\u30FC\u30D7\u304C\u3042\u3063\u3066\u3082\u3088\u3044\
    \ (\u89AA\u3078\u623B\u308B\u8FBA\u306F\u9802\u70B9\u3067\u306F\u306A\u304F\u8FBA\
    \u306E\u756A\u53F7\u3067\u533A\u5225\u3059\u308B)\n * \u81EA\u5DF1\u30EB\u30FC\
    \u30D7\u306F\u3069\u306E\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u306E\
    \u8FBA\u306B\u3082\u5165\u308C\u306A\u3044\n * \u4F8B:\n * LowLink ll(g);\n *\
    \ ll.articulation_points(); ll.bridges(); ll.two_edge_connected_groups();\n *\
    \ ll.two_vertex_connected_groups(); ll.block_cut_tree();\n *\n * @tparam Cost\
    \ \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B\n */\ntemplate <typename Cost = long\
    \ long>\nclass LowLink {\n    long long n;\n    std::vector<bool> art, bridge;\n\
    \    std::vector<long long> arts, bridge_ids;\n    std::vector<int> comp;\n  \
    \  std::vector<std::vector<long long>> groups;\n    std::vector<std::vector<long\
    \ long>> bc_groups, bc_edge_groups;\n    std::vector<long long> bc_edge_id;\n\n\
    \   public:\n    std::vector<long long> ord;  //!< DFS \u3067\u8A2A\u308C\u305F\
    \u9806\u756A\n    std::vector<long long> low;  //!< DFS \u6728\u306E\u5B50\u5B6B\
    \u304B\u3089\u3001\u6728\u306E\u8FBA\u3092\u9006\u306B\u305F\u3069\u3089\u305A\
    \u306B 1 \u672C\u306E\u5F8C\u9000\u8FBA\u3067\u884C\u3051\u308B\u9802\u70B9\u306E\
    \ ord \u306E\u6700\u5C0F\u5024\n\n    explicit LowLink(const Graph<Cost>& graph)\
    \ : n(graph.n), art(n), bridge(graph.m), comp(n, -1), bc_edge_id(graph.m, -1),\
    \ ord(n, -1), low(n) {\n        std::vector<int> parent(n, -1), parent_edge(n,\
    \ -1), iter(n, 0);\n        std::vector<long long> st;\n        // \u4E8C\u91CD\
    \u9802\u70B9\u9023\u7D50\u6210\u5206\u3092\u4F5C\u308B\u305F\u3081\u306B\u3001\
    \u901A\u3063\u305F\u8FBA (\u6728\u306E\u8FBA\u3068\u3001\u5B50\u5B6B\u304B\u3089\
    \u7956\u5148\u3078\u306E\u5F8C\u9000\u8FBA) \u3092\u7A4D\u3080\n        std::vector<long\
    \ long> edge_st, edge_src(graph.m), edge_dst(graph.m), last_block(n, -1);\n  \
    \      auto push_edge = [&](long long id, long long a, long long b) {\n      \
    \      edge_st.push_back(id);\n            edge_src[id] = a, edge_dst[id] = b;\n\
    \        };\n        long long k = 0;\n        for (long long root = 0; root <\
    \ n; root++) {\n            if (ord[root] != -1) continue;\n            int root_children\
    \ = 0;\n            ord[root] = low[root] = k++;\n            st.push_back(root);\n\
    \            while (!st.empty()) {\n                long long v = st.back();\n\
    \                if (iter[v] < static_cast<int>(graph[v].size())) {\n        \
    \            const auto& e = graph[v][iter[v]++];\n                    if (e.id\
    \ == parent_edge[v]) continue;\n                    long long u = e.dst;\n   \
    \                 if (ord[u] == -1) {\n                        parent[u] = v;\n\
    \                        parent_edge[u] = e.id;\n                        ord[u]\
    \ = low[u] = k++;\n                        st.push_back(u);\n                \
    \        push_edge(e.id, v, u);\n                    } else {\n              \
    \          low[v] = std::min(low[v], ord[u]);\n                        // \u5F8C\
    \u9000\u8FBA\u306F\u5B50\u5B6B\u306E\u5074\u304B\u3089\u898B\u305F\u3068\u304D\
    \u306B 1 \u56DE\u3060\u3051\u7A4D\u3080 (\u81EA\u5DF1\u30EB\u30FC\u30D7\u306F\u7A4D\
    \u307E\u306A\u3044)\n                        if (ord[u] < ord[v]) push_edge(e.id,\
    \ v, u);\n                    }\n                    continue;\n             \
    \   }\n                st.pop_back();\n                if (v == root) continue;\n\
    \                long long p = parent[v];\n                low[p] = std::min(low[p],\
    \ low[v]);\n                if (low[v] > ord[p]) bridge[parent_edge[v]] = true;\n\
    \                if (low[v] >= ord[p]) {\n                    // \u89AA\u3068\u306E\
    \u8FBA\u307E\u3067\u304C 1 \u3064\u306E\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\
    \u5206\n                    long long b = bc_groups.size();\n                \
    \    bc_groups.emplace_back();\n                    bc_edge_groups.emplace_back();\n\
    \                    while (true) {\n                        long long id = edge_st.back();\n\
    \                        edge_st.pop_back();\n                        bc_edge_id[id]\
    \ = b;\n                        bc_edge_groups[b].push_back(id);\n           \
    \             for (long long w : {edge_src[id], edge_dst[id]}) {\n           \
    \                 if (last_block[w] != b) last_block[w] = b, bc_groups[b].push_back(w);\n\
    \                        }\n                        if (id == parent_edge[v])\
    \ break;\n                    }\n                }\n                if (p == root)\n\
    \                    root_children++;\n                else if (low[v] >= ord[p])\n\
    \                    art[p] = true;\n            }\n            if (root_children\
    \ >= 2) art[root] = true;\n            // \u307B\u304B\u306E\u9802\u70B9\u3068\
    \u3064\u306A\u304C\u3063\u3066\u3044\u306A\u3044\u9802\u70B9\u306F\u3001\u305D\
    \u308C\u3060\u3051\u3067 1 \u3064\u306E\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\
    \u5206\n            if (root_children == 0) {\n                bc_groups.push_back({root});\n\
    \                bc_edge_groups.emplace_back();\n            }\n        }\n  \
    \      for (long long v = 0; v < n; v++) {\n            if (art[v]) arts.push_back(v);\n\
    \        }\n        for (long long id = 0; id < graph.m; id++) {\n           \
    \ if (bridge[id]) bridge_ids.push_back(id);\n        }\n        // \u6A4B\u3092\
    \u901A\u3089\u305A\u306B\u884C\u3051\u308B\u9802\u70B9\u3092\u307E\u3068\u3081\
    \u308B\n        for (long long s = 0; s < n; s++) {\n            if (comp[s] !=\
    \ -1) continue;\n            comp[s] = groups.size();\n            groups.push_back({s});\n\
    \            for (long long i = 0; i < static_cast<long long>(groups.back().size());\
    \ i++) {\n                long long v = groups.back()[i];\n                for\
    \ (const auto& e : graph[v]) {\n                    if (bridge[e.id] || comp[e.dst]\
    \ != -1) continue;\n                    comp[e.dst] = comp[s];\n             \
    \       groups.back().push_back(e.dst);\n                }\n            }\n  \
    \      }\n    }\n\n    /**\n     * @brief \u9802\u70B9\u6570\n     */\n    long\
    \ long size() const { return n; }\n\n    /**\n     * @brief v \u304C\u95A2\u7BC0\
    \u70B9 (\u53D6\u308A\u9664\u304F\u3068\u9023\u7D50\u6210\u5206\u304C\u5897\u3048\
    \u308B\u9802\u70B9) \u304B\n     */\n    bool is_articulation_point(long long\
    \ v) const {\n        assert(0 <= v && v < n);\n        return art[v];\n    }\n\
    \    /**\n     * @brief \u756A\u53F7 id \u306E\u8FBA\u304C\u6A4B (\u53D6\u308A\
    \u9664\u304F\u3068\u9023\u7D50\u6210\u5206\u304C\u5897\u3048\u308B\u8FBA) \u304B\
    \n     */\n    bool is_bridge(long long id) const {\n        assert(0 <= id &&\
    \ id < static_cast<long long>(bridge.size()));\n        return bridge[id];\n \
    \   }\n    /**\n     * @brief \u95A2\u7BC0\u70B9\u306E\u9802\u70B9\u756A\u53F7\
    \u306E\u6607\u9806\u306E\u30EA\u30B9\u30C8\n     */\n    const std::vector<long\
    \ long>& articulation_points() const { return arts; }\n    /**\n     * @brief\
    \ \u6A4B\u306E\u8FBA\u306E\u756A\u53F7\u306E\u6607\u9806\u306E\u30EA\u30B9\u30C8\
    \n     */\n    const std::vector<long long>& bridges() const { return bridge_ids;\
    \ }\n    /**\n     * @brief \u9802\u70B9 v \u304C\u5C5E\u3059\u308B\u4E8C\u91CD\
    \u8FBA\u9023\u7D50\u6210\u5206\u306E\u756A\u53F7\n     */\n    long long two_edge_connected_group_id(long\
    \ long v) const {\n        assert(0 <= v && v < n);\n        return comp[v];\n\
    \    }\n    /**\n     * @brief \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206 (\u6A4B\
    \u3092\u53D6\u308A\u9664\u3044\u305F\u3068\u304D\u306E\u9023\u7D50\u6210\u5206\
    ) \u3054\u3068\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\n     */\n    const std::vector<std::vector<long\
    \ long>>& two_edge_connected_groups() const { return groups; }\n\n    /**\n  \
    \   * @brief \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u3054\u3068\u306E\
    \u9802\u70B9\u306E\u30EA\u30B9\u30C8\n     * \u95A2\u7BC0\u70B9\u306F\u8907\u6570\
    \u306E\u6210\u5206\u306B\u5165\u308B\u3002\u307B\u304B\u306E\u9802\u70B9\u3068\
    \u3064\u306A\u304C\u3063\u3066\u3044\u306A\u3044\u9802\u70B9\u306F\u3001\u305D\
    \u308C\u3060\u3051\u3067 1 \u3064\u306E\u6210\u5206\u306B\u306A\u308B\n     */\n\
    \    const std::vector<std::vector<long long>>& two_vertex_connected_groups()\
    \ const { return bc_groups; }\n    /**\n     * @brief \u4E8C\u91CD\u9802\u70B9\
    \u9023\u7D50\u6210\u5206\u3054\u3068\u306E\u8FBA\u306E\u756A\u53F7\u306E\u30EA\
    \u30B9\u30C8 (two_vertex_connected_groups() \u3068\u540C\u3058\u9806)\n     *\
    \ \u81EA\u5DF1\u30EB\u30FC\u30D7\u4EE5\u5916\u306E\u8FBA\u306F\u3061\u3087\u3046\
    \u3069 1 \u3064\u306E\u6210\u5206\u306B\u5165\u308B\n     */\n    const std::vector<std::vector<long\
    \ long>>& two_vertex_connected_edge_groups() const { return bc_edge_groups; }\n\
    \    /**\n     * @brief \u756A\u53F7 id \u306E\u8FBA\u304C\u5C5E\u3059\u308B\u4E8C\
    \u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u306E\u756A\u53F7 (\u81EA\u5DF1\u30EB\
    \u30FC\u30D7\u306A\u3089 -1)\n     */\n    long long two_vertex_connected_group_id(long\
    \ long id) const {\n        assert(0 <= id && id < static_cast<long long>(bc_edge_id.size()));\n\
    \        return bc_edge_id[id];\n    }\n    /**\n     * @brief Block-Cut Tree\n\
    \     * \u9802\u70B9 0, ..., n - 1 \u306F\u5143\u306E\u9802\u70B9\u3001\u9802\u70B9\
    \ n + b \u306F\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206 b \u3067\u3001\u5143\
    \u306E\u9802\u70B9\u3068\u3001\u305D\u308C\u3092\u542B\u3080\u6210\u5206\u3092\
    \u8FBA\u3067\u7D50\u3076\n     * \u5143\u306E\u30B0\u30E9\u30D5\u304C\u9023\u7D50\
    \u306A\u3089\u6728\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070\u68EE\u306B\
    \u306A\u308B (\u68EE\u306E\u3068\u304D\u306F\u3001\u9023\u7D50\u3067\u3042\u308B\
    \u3053\u3068\u3092\u524D\u63D0\u3068\u3059\u308B\u6728\u306E\u95A2\u6570\u306B\
    \u306F\u6E21\u305B\u306A\u3044)\n     */\n    Tree<int> block_cut_tree() const\
    \ {\n        Tree<int> res(n + static_cast<long long>(bc_groups.size()));\n  \
    \      for (long long b = 0; b < static_cast<long long>(bc_groups.size()); b++)\
    \ {\n            for (long long v : bc_groups[b]) res.add_edge(v, n + b);\n  \
    \      }\n        return res;\n    }\n};\n"
  dependsOn:
  - src/graph/graph.hpp
  - src/graph/tree.hpp
  isVerificationFile: false
  path: src/graph/lowlink.hpp
  requiredBy: []
  timestamp: '2026-10-31 18:12:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/graph/lowlink.test.cpp
  - test/aoj/grl/grl-3-a.test.cpp
  - test/aoj/grl/grl-3-b.test.cpp
  - test/yosupo/graph/two-edge-connected-components.test.cpp
  - test/yosupo/graph/biconnected-components.test.cpp
documentation_of: src/graph/lowlink.hpp
layout: document
title: "lowlink (\u95A2\u7BC0\u70B9\u3001\u6A4B\u3001\u4E8C\u91CD\u8FBA\u9023\u7D50\
  \u6210\u5206\u5206\u89E3\u3001\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\
  \u89E3\u3001Block-Cut Tree)"
---

無向の [グラフ](graph.hpp) について、DFS の lowlink を求め、関節点・橋・二重辺連結成分・二重頂点連結成分と Block-Cut Tree を求めます。DFS は再帰を使わないので、深いグラフでもスタックがあふれません。$O(n + m)$ です。

多重辺と自己ループがあってもかまいません。親へ戻る辺は、頂点ではなく辺の番号で区別しています。自己ループは連結性に関係しないので、どの二重頂点連結成分の辺にも入れません。

```cpp
Graph<int> g(n);
g.read(m, 0);
LowLink ll(g);
for (long long v : ll.articulation_points()) { /* 関節点 */ }
for (long long id : ll.bridges()) { auto e = g.edges()[id]; /* 橋 e.src - e.dst */ }
auto groups = ll.two_edge_connected_groups();
auto blocks = ll.two_vertex_connected_groups();  // 二重頂点連結成分ごとの頂点
Tree<int> bct = ll.block_cut_tree();             // 頂点 n + b が成分 b
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `LowLink(g)` | 無向グラフ `g` から求める | $O(n + m)$ |
| `size()` | 頂点数 | $O(1)$ |
| `articulation_points()` | 関節点 (取り除くと連結成分が増える頂点) の番号の昇順のリスト | $O(1)$ |
| `is_articulation_point(v)` | `v` が関節点か | $O(1)$ |
| `bridges()` | 橋 (取り除くと連結成分が増える辺) の辺の番号 (`Edge::id`) の昇順のリスト | $O(1)$ |
| `is_bridge(id)` | 番号 `id` の辺が橋か | $O(1)$ |
| `two_edge_connected_groups()` | 二重辺連結成分 (橋をすべて取り除いたときの連結成分) ごとの頂点のリスト | $O(1)$ |
| `two_edge_connected_group_id(v)` | `v` が属する二重辺連結成分の番号 (`two_edge_connected_groups()` の添字) | $O(1)$ |
| `two_vertex_connected_groups()` | 二重頂点連結成分ごとの頂点のリスト。関節点は複数の成分に入る。ほかの頂点とつながっていない頂点は、それだけで 1 つの成分になる | $O(1)$ |
| `two_vertex_connected_edge_groups()` | 二重頂点連結成分ごとの辺の番号のリスト (`two_vertex_connected_groups()` と同じ順)。自己ループ以外の辺はちょうど 1 つの成分に入る | $O(1)$ |
| `two_vertex_connected_group_id(id)` | 番号 `id` の辺が属する二重頂点連結成分の番号 (自己ループなら -1) | $O(1)$ |
| `block_cut_tree()` | Block-Cut Tree を [`Tree<int>`](tree.hpp) で返す (下を参照) | $O(n + m)$ |

頂点番号・辺の番号・成分の番号は `long long` です。

## メンバ変数

| 変数 | 説明 |
|---|---|
| `ord[v]` | DFS で訪れた順番 |
| `low[v]` | DFS 木の子孫から、木の辺を逆にたどらずに 1 本の後退辺で行ける頂点の `ord` の最小値 (lowlink の値) |

## 二重頂点連結成分と Block-Cut Tree

二重頂点連結成分は、どの頂点を 1 つ取り除いても連結なままの、極大な部分グラフです。どの辺もちょうど 1 つの成分に入り、関節点だけが複数の成分にまたがります。橋は、その辺だけで 1 つの成分になります。

`block_cut_tree()` は、頂点 $0, \dots, n - 1$ を元の頂点、頂点 $n + b$ を成分 $b$ として、元の頂点と、それを含む成分を辺で結んだグラフを返します。元のグラフが連結なら木、そうでなければ森です。森のときは、[HL 分解](heavy-light-decomposition.hpp) などの連結であることを前提とする木の関数には渡せません。

- 元の頂点の次数は、それを含む成分の個数です。次数が 2 以上なのは関節点だけです。
- $u$ から $v$ へのどの道も必ず通る頂点は、Block-Cut Tree 上の $u$ と $v$ を結ぶパスにある元の頂点 (端の $u$、$v$ を除く) です。HL 分解に渡せば、パスの長さなどからクエリに答えられます。
- 頂点 $x$ を取り除いたときに増える連結成分の数は、Block-Cut Tree での $x$ の次数から 1 を引いた数です (ほかの頂点とつながっていない $x$ なら、成分が 1 つ減ります)。

## 関連

- 有向グラフの強連結成分分解は [グラフに関する関数](graph_util.hpp) の `strongly_connected_components`
