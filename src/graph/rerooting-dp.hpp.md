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
    path: test/aoj/volume15/1595.test.cpp
    title: test/aoj/volume15/1595.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/graph/rerooting-dp.test.cpp
    title: test/unittest/graph/rerooting-dp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5168\u65B9\u4F4D\u6728DP"
    links: []
  bundledCode: "#line 2 \"src/graph/rerooting-dp.hpp\"\n\n/**\n * @file rerooting-dp.hpp\n\
    \ * @brief \u5168\u65B9\u4F4D\u6728DP\n */\n#include <algorithm>\n#include <cstddef>\n\
    #include <type_traits>\n#include <utility>\n#include <vector>\n\n#line 2 \"src/graph/tree.hpp\"\
    \n\n/**\n * @file tree.hpp\n * @brief \u6728\u306E\u6C4E\u7528\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n */\n\n#line 9 \"src/graph/tree.hpp\"\n#include <cassert>\n\
    #include <stack>\n#line 14 \"src/graph/tree.hpp\"\n\n#line 2 \"src/graph/graph.hpp\"\
    \n\n/**\n * @file graph.hpp\n * @brief \u30B0\u30E9\u30D5\n */\n\n#line 9 \"src/graph/graph.hpp\"\
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
    \u308B\n     */\n    std::vector<Edge> edges() const {\n        std::vector<Edge>\
    \ res(m);\n        for (long long i = 0; i < n; i++) {\n            for (auto&\
    \ e : g[i]) {\n                res[e.id] = e;\n            }\n        }\n    \
    \    return res;\n    }\n};\n#line 16 \"src/graph/tree.hpp\"\n\ntemplate <typename>\n\
    class RootedTree;\ntemplate <typename>\nclass DoublingClimbTree;\n\n/**\n * @brief\
    \ \u6839\u306A\u3057\u6728\n *\n * @tparam Cost = long long \u8FBA\u306E\u91CD\
    \u307F\n *\n * Graph<Cost>\u3092\u7D99\u627F\u3057\u3001\u3059\u3079\u3066\u7121\
    \u5411\u8FBA\u3067\u8868\u3059\n */\ntemplate <typename Cost = long long>\nstruct\
    \ Tree : private Graph<Cost> {\n    // Graph<Cost>* g = new Tree<Cost>(); \u304C\
    \u3067\u304D\u3066\u3057\u307E\u3046\u3068\u3001delete\u6642\u306B\u30E1\u30E2\
    \u30EA\u30EA\u30FC\u30AF\u304C\u767A\u751F\n    // \u56DE\u907F\u3059\u308B\u305F\
    \u3081private\u7D99\u627F\u306B\u3057\u3066\u3001\u30E1\u30F3\u30D0\u3092\u3059\
    \u3079\u3066using\u5BA3\u8A00\n    using Edge = typename Graph<Cost>::Edge;\n\
    \    using Graph<Cost>::n;\n    using Graph<Cost>::size;\n    using Graph<Cost>::m;\n\
    \    using Graph<Cost>::g;\n    using Graph<Cost>::Graph;\n    using Graph<Cost>::add_edge;\n\
    \    using Graph<Cost>::add_directed_edge;\n    using Graph<Cost>::operator[];\n\
    \    using Graph<Cost>::edges;\n\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n     *\n     * @param n \u30CE\u30FC\u30C9\u6570\n     */\n\
    \    explicit Tree(long long n = 0) : Graph<Cost>(n) {}\n\n    /**\n     * @brief\
    \ Graph \u3068\u3057\u3066\u898B\u308B\n     *\n     * Graph \u3092\u53D7\u3051\
    \u53D6\u308B\u95A2\u6570 (shortest_path \u306A\u3069) \u306B\u6E21\u3059\u3068\
    \u304D\u306B\u4F7F\u3046\n     * @return const Graph<Cost>& \u3053\u306E\u6728\
    \u3092\u8868\u3059\u30B0\u30E9\u30D5\n     */\n    const Graph<Cost>& graph()\
    \ const { return *this; }\n\n    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\
    \u6A19\u6E96\u5165\u529B\u304B\u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\
    \u3059\u308B\n     * @param padding  = -1 \u9802\u70B9\u756A\u53F7\u3092\u5165\
    \u529B\u304B\u3089\u3044\u304F\u3064\u305A\u3089\u3059\u304B\n     * @param weighted\
    \ = false \u8FBA\u306E\u91CD\u307F\u304C\u5165\u529B\u3055\u308C\u308B\u304B\n\
    \     */\n    void read(long long padding = -1, bool weighted = false) {\n   \
    \     Graph<Cost>::read(this->n - 1, padding, weighted, false);\n    }\n\n   \
    \ /**\n     * @brief \u6839\u4ED8\u304D\u6728\u306B\u3059\u308B\n     *\n    \
    \ * @param root \u6839\n     * @return RootedTree<Cost> \u6839\u4ED8\u304D\u6728\
    \u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    RootedTree<Cost>\
    \ set_root(long long root) const& {\n        return RootedTree<Cost>(*this, root);\n\
    \    }\n    /**\n     * @brief \u6839\u4ED8\u304D\u6728\u306B\u3057\u3066\u8FD4\
    \u3059\n     *\n     * @param root \u6839\n     * @return RootedTree<Cost> \u6839\
    \u4ED8\u304D\u6728\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n\
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
    \u6BB5\u6570\n     * @return long long k\u56DE\u767B\u3063\u305F\u9802\u70B9\n\
    \     */\n    long long hop(long long u, long long k) const {\n        assert(0\
    \ <= u && u < this->n && k >= 0);\n        if (k > this->unweighted_depth[u])\
    \ return -1;\n        for (long long i = 0; i < h; i++) {\n            if (k >>\
    \ i & 1) u = doubling_par[i][u];\n            if (u == -1) return -1;\n      \
    \  }\n        return u;\n    }\n\n    /**\n     * @brief \u6700\u5C0F\u5171\u901A\
    \u7956\u5148\n     *\n     * @param u \u9802\u70B91\n     * @param v \u9802\u70B9\
    2\n     * @return long long LCA\u306E\u9802\u70B9\u756A\u53F7\n     */\n    long\
    \ long lca(long long u, long long v) const {\n        assert(0 <= u && u < this->n\
    \ && 0 <= v && v < this->n);\n        if (this->unweighted_depth[u] > this->unweighted_depth[v])\
    \ std::swap(u, v);\n        v = hop(v, this->unweighted_depth[v] - this->unweighted_depth[u]);\n\
    \        if (u == v) return u;\n        for (long long i = h - 1; i >= 0; i--)\
    \ {\n            long long nu = doubling_par[i][u];\n            long long nv\
    \ = doubling_par[i][v];\n            if (nu == -1) continue;\n            if (nu\
    \ != nv) {\n                u = nu;\n                v = nv;\n            }\n\
    \        }\n        return this->par[u];\n    }\n\n    /**\n     * @brief \u9802\
    \u70B9\u9593\u8DDD\u96E2(\u91CD\u307F\u4ED8\u304D)\n     *\n     * @param u \u9802\
    \u70B91\n     * @param v \u9802\u70B92\n     * @return Cost u\u3068v\u9593\u306E\
    \u6700\u77ED\u7D4C\u8DEF\u306E\u8FBA\u306E\u91CD\u307F\u306E\u548C\n     */\n\
    \    Cost dist(long long u, long long v) const {\n        return this->depth[u]\
    \ + this->depth[v] - this->depth[lca(u, v)] * 2;\n    }\n\n   private:\n    void\
    \ build() {\n        long long n = this->n;\n        h = 1;\n        while ((1LL\
    \ << h) < n) h++;\n        doubling_par.assign(h, std::vector<long long>(n, -1));\n\
    \        for (long long i = 0; i < n; i++) doubling_par[0][i] = this->par[i];\n\
    \        for (long long i = 0; i < h - 1; i++) {\n            for (long long j\
    \ = 0; j < n; j++) {\n                if (doubling_par[i][j] != -1) {\n      \
    \              doubling_par[i + 1][j] = doubling_par[i][doubling_par[i][j]];\n\
    \                }\n            }\n        }\n    }\n};\n#line 14 \"src/graph/rerooting-dp.hpp\"\
    \n\n/**\n * @brief \u5168\u65B9\u4F4D\u6728DP\n * dp[u] = addnode(merge(addedge(dp[v1],\
    \ uv1.cost, uv1.id), merge(addedge(dp[v2], uv2.cost, uv2.id), ...)), u) v_i\u306F\
    u\u306E\u5B50\n *\n * @tparam E \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\n * @tparam\
    \ V DP\u306E\u578B\n * @param tree\n * @param e \u53EF\u63DB\u30E2\u30CE\u30A4\
    \u30C9\u306E\u5358\u4F4D\u5143\n * @param merge (E,E)->E \u53EF\u63DB\n * @param\
    \ addedge (V,Cost,long long)->E \u8FBA\u306E\u756A\u53F7\u306F long long \u3067\
    \u6E21\u3059 (int \u3067\u53D7\u3051\u53D6\u3063\u3066\u3082\u3088\u3044)\n *\
    \ @param addnode (E,long long)->V \u9802\u70B9\u756A\u53F7\u306F long long \u3067\
    \u6E21\u3059 (int \u3067\u53D7\u3051\u53D6\u3063\u3066\u3082\u3088\u3044)\n *\
    \ @return std::vector<V>\n */\ntemplate <typename E, typename V = E, class Merge,\
    \ class AddEdge, class AddNode, typename Cost>\nstd::vector<V> rerooting_dp(const\
    \ Tree<Cost>& tree, E e, Merge merge, AddEdge addedge, AddNode addnode) {\n  \
    \  static_assert(std::is_invocable_r_v<E, Merge, E, E>);\n    static_assert(std::is_invocable_r_v<E,\
    \ AddEdge, V, Cost, long long>);\n    static_assert(std::is_invocable_r_v<V, AddNode,\
    \ E, long long>);\n    RootedTree<Cost> rooted(tree, 0);\n    std::vector<V> subdp(rooted.n);\n\
    \    for (long long u : rooted.postorder) {\n        E tmp = e;\n        for (auto\
    \ edge : rooted.child[u]) {\n            tmp = merge(tmp, addedge(subdp[edge.dst],\
    \ edge.cost, edge.id));\n        }\n        subdp[u] = addnode(tmp, u);\n    }\n\
    \    std::vector<V> dp(rooted.n);\n    std::vector<E> pe(rooted.n, e);\n    for\
    \ (long long u : rooted.preorder) {\n        const auto& ch = rooted.child[u];\n\
    \        std::vector<E> ri(ch.size() + 1, e);\n        for (std::size_t i = ch.size();\
    \ i > 0; i--) {\n            ri[i - 1] = merge(ri[i], addedge(subdp[ch[i - 1].dst],\
    \ ch[i - 1].cost, ch[i - 1].id));\n        }\n        dp[u] = addnode(merge(pe[u],\
    \ ri[0]), u);\n        E le = pe[u];\n        for (std::size_t i = 0; i < ch.size();\
    \ i++) {\n            pe[ch[i].dst] = addedge(addnode(merge(le, ri[i + 1]), u),\
    \ ch[i].cost, ch[i].id);\n            le = merge(le, addedge(subdp[ch[i].dst],\
    \ ch[i].cost, ch[i].id));\n        }\n    }\n    return dp;\n}\n\n/**\n * @brief\
    \ \u6700\u3082\u9060\u3044\u9802\u70B9\u307E\u3067\u306E\u8DDD\u96E2\n */\ntemplate\
    \ <typename Cost>\ninline std::vector<Cost> farthest_node_dist(const Tree<Cost>&\
    \ tree) {\n    return rerooting_dp(\n        tree,\n        Cost{},\n        [](Cost\
    \ a, Cost b) { return std::max<Cost>(a, b); },\n        [](Cost a, Cost c, long\
    \ long) { return a + c; },\n        [](Cost a, long long) { return a; });\n}\n\
    \n/**\n * @brief \u4ED6\u306E\u5168\u3066\u306E\u9802\u70B9\u3068\u306E\u8DDD\u96E2\
    \u306E\u5408\u8A08\n */\ntemplate <typename Cost>\ninline std::vector<Cost> distance_sums(const\
    \ Tree<Cost>& tree) {\n    using P = typename std::pair<Cost, int>;\n    auto\
    \ tmp = rerooting_dp(\n        tree,\n        P{{}, 0},\n        [](P a, P b)\
    \ { return P{a.first + b.first, a.second + b.second}; },\n        [](P a, Cost\
    \ c, long long) { return P{a.first + a.second * c, a.second}; },\n        [](P\
    \ a, long long) { return P{a.first, a.second + 1}; });\n    std::vector<Cost>\
    \ res;\n    res.reserve(tree.n);\n    for (const P& s : tmp) res.push_back(s.first);\n\
    \    return res;\n}\n\n/**\n * @brief \u305D\u306E\u9802\u70B9\u3092\u542B\u3080\
    \u9023\u7D50\u306A\u90E8\u5206\u30B0\u30E9\u30D5\u306E\u500B\u6570\n */\ntemplate\
    \ <typename V, typename Cost>\ninline std::vector<V> connected_subgraph_count(const\
    \ Tree<Cost>& tree) {\n    return rerooting_dp(\n        tree,\n        V(1),\n\
    \        [](V a, V b) { return a * b; },\n        [](V a, Cost, long long) { return\
    \ a + 1; },\n        [](V a, long long) { return a; });\n}\n"
  code: "#pragma once\n\n/**\n * @file rerooting-dp.hpp\n * @brief \u5168\u65B9\u4F4D\
    \u6728DP\n */\n#include <algorithm>\n#include <cstddef>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n\n#include \"tree.hpp\"\n\n/**\n * @brief\
    \ \u5168\u65B9\u4F4D\u6728DP\n * dp[u] = addnode(merge(addedge(dp[v1], uv1.cost,\
    \ uv1.id), merge(addedge(dp[v2], uv2.cost, uv2.id), ...)), u) v_i\u306Fu\u306E\
    \u5B50\n *\n * @tparam E \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\n * @tparam V DP\u306E\
    \u578B\n * @param tree\n * @param e \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u306E\
    \u5358\u4F4D\u5143\n * @param merge (E,E)->E \u53EF\u63DB\n * @param addedge (V,Cost,long\
    \ long)->E \u8FBA\u306E\u756A\u53F7\u306F long long \u3067\u6E21\u3059 (int \u3067\
    \u53D7\u3051\u53D6\u3063\u3066\u3082\u3088\u3044)\n * @param addnode (E,long long)->V\
    \ \u9802\u70B9\u756A\u53F7\u306F long long \u3067\u6E21\u3059 (int \u3067\u53D7\
    \u3051\u53D6\u3063\u3066\u3082\u3088\u3044)\n * @return std::vector<V>\n */\n\
    template <typename E, typename V = E, class Merge, class AddEdge, class AddNode,\
    \ typename Cost>\nstd::vector<V> rerooting_dp(const Tree<Cost>& tree, E e, Merge\
    \ merge, AddEdge addedge, AddNode addnode) {\n    static_assert(std::is_invocable_r_v<E,\
    \ Merge, E, E>);\n    static_assert(std::is_invocable_r_v<E, AddEdge, V, Cost,\
    \ long long>);\n    static_assert(std::is_invocable_r_v<V, AddNode, E, long long>);\n\
    \    RootedTree<Cost> rooted(tree, 0);\n    std::vector<V> subdp(rooted.n);\n\
    \    for (long long u : rooted.postorder) {\n        E tmp = e;\n        for (auto\
    \ edge : rooted.child[u]) {\n            tmp = merge(tmp, addedge(subdp[edge.dst],\
    \ edge.cost, edge.id));\n        }\n        subdp[u] = addnode(tmp, u);\n    }\n\
    \    std::vector<V> dp(rooted.n);\n    std::vector<E> pe(rooted.n, e);\n    for\
    \ (long long u : rooted.preorder) {\n        const auto& ch = rooted.child[u];\n\
    \        std::vector<E> ri(ch.size() + 1, e);\n        for (std::size_t i = ch.size();\
    \ i > 0; i--) {\n            ri[i - 1] = merge(ri[i], addedge(subdp[ch[i - 1].dst],\
    \ ch[i - 1].cost, ch[i - 1].id));\n        }\n        dp[u] = addnode(merge(pe[u],\
    \ ri[0]), u);\n        E le = pe[u];\n        for (std::size_t i = 0; i < ch.size();\
    \ i++) {\n            pe[ch[i].dst] = addedge(addnode(merge(le, ri[i + 1]), u),\
    \ ch[i].cost, ch[i].id);\n            le = merge(le, addedge(subdp[ch[i].dst],\
    \ ch[i].cost, ch[i].id));\n        }\n    }\n    return dp;\n}\n\n/**\n * @brief\
    \ \u6700\u3082\u9060\u3044\u9802\u70B9\u307E\u3067\u306E\u8DDD\u96E2\n */\ntemplate\
    \ <typename Cost>\ninline std::vector<Cost> farthest_node_dist(const Tree<Cost>&\
    \ tree) {\n    return rerooting_dp(\n        tree,\n        Cost{},\n        [](Cost\
    \ a, Cost b) { return std::max<Cost>(a, b); },\n        [](Cost a, Cost c, long\
    \ long) { return a + c; },\n        [](Cost a, long long) { return a; });\n}\n\
    \n/**\n * @brief \u4ED6\u306E\u5168\u3066\u306E\u9802\u70B9\u3068\u306E\u8DDD\u96E2\
    \u306E\u5408\u8A08\n */\ntemplate <typename Cost>\ninline std::vector<Cost> distance_sums(const\
    \ Tree<Cost>& tree) {\n    using P = typename std::pair<Cost, int>;\n    auto\
    \ tmp = rerooting_dp(\n        tree,\n        P{{}, 0},\n        [](P a, P b)\
    \ { return P{a.first + b.first, a.second + b.second}; },\n        [](P a, Cost\
    \ c, long long) { return P{a.first + a.second * c, a.second}; },\n        [](P\
    \ a, long long) { return P{a.first, a.second + 1}; });\n    std::vector<Cost>\
    \ res;\n    res.reserve(tree.n);\n    for (const P& s : tmp) res.push_back(s.first);\n\
    \    return res;\n}\n\n/**\n * @brief \u305D\u306E\u9802\u70B9\u3092\u542B\u3080\
    \u9023\u7D50\u306A\u90E8\u5206\u30B0\u30E9\u30D5\u306E\u500B\u6570\n */\ntemplate\
    \ <typename V, typename Cost>\ninline std::vector<V> connected_subgraph_count(const\
    \ Tree<Cost>& tree) {\n    return rerooting_dp(\n        tree,\n        V(1),\n\
    \        [](V a, V b) { return a * b; },\n        [](V a, Cost, long long) { return\
    \ a + 1; },\n        [](V a, long long) { return a; });\n}\n"
  dependsOn:
  - src/graph/tree.hpp
  - src/graph/graph.hpp
  isVerificationFile: false
  path: src/graph/rerooting-dp.hpp
  requiredBy: []
  timestamp: '2026-10-22 19:53:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/graph/rerooting-dp.test.cpp
  - test/aoj/volume15/1595.test.cpp
documentation_of: src/graph/rerooting-dp.hpp
layout: document
title: "\u5168\u65B9\u4F4D\u6728DP"
---

[木](tree.hpp) `Tree<Cost>` のすべての頂点について、その頂点を根としたときの木 DP の値を $O(n)$ で求めます。

例: 各頂点から最も遠い頂点までの距離 (下の `farthest_node_dist` と同じ)

```cpp
Tree<long long> t(n);
t.read(-1, true);
auto dp = rerooting_dp(
    t, 0LL,
    [](long long a, long long b) { return std::max(a, b); },  // merge: 子の中で最大
    [](long long x, long long c, long long) { return x + c; },  // addedge: 辺の重みを足す
    [](long long a, long long) { return a; });                  // addnode: そのまま
```

## `rerooting_dp<E, V = E>(tree, e, merge, addedge, addnode)` の引数

頂点 $u$ の子を $v_1, v_2, \dots$ とすると、次のように計算した `dp[u]` (型 `V`) を全頂点について返します。

$$\mathrm{dp}[u] = \mathrm{addnode}(\mathrm{merge}(\mathrm{addedge}(\mathrm{dp}[v_1], \mathrm{cost}_1, \mathrm{id}_1), \mathrm{merge}(\mathrm{addedge}(\mathrm{dp}[v_2], \dots), \dots)), u)$$

| 引数 | 型 | 意味 |
|---|---|---|
| `e` | `E` | `merge` の単位元 (子がないときの値) |
| `merge(a, b)` | `(E, E) -> E` | 子からの値をまとめる。可換かつ結合的であること |
| `addedge(x, cost, id)` | `(V, Cost, long long) -> E` | 子の DP 値 `x` に、子へ向かう辺 (重み `cost`、番号 `id`) の分を加える |
| `addnode(a, u)` | `(E, long long) -> V` | まとめた値 `a` に頂点 `u` の分を加えて、`u` の DP 値にする |

辺の番号 `id` と頂点 `u` は `long long` で渡します。`int` で受け取る関数でもかまいません。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `rerooting_dp<E, V = E>(tree, e, merge, addedge, addnode)` | 各頂点を根としたときの DP 値 (上の説明を参照) | $O(n)$ (`merge`・`addedge`・`addnode` の呼び出しが $O(n)$ 回) |
| `farthest_node_dist(tree)` | 各頂点から最も遠い頂点までの距離 (重み付き) | $O(n)$ |
| `distance_sums(tree)` | 各頂点から他のすべての頂点への距離の合計 (重み付き) | $O(n)$ |
| `connected_subgraph_count<V>(tree)` | 各頂点について、その頂点を含む連結な部分グラフ (頂点集合) の個数。`V` は `mint` など | $O(n)$ |

## 関連

- 木の直径・LCA などは [木の汎用テンプレート](tree.hpp)
