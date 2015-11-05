--[[ _list_node ]]

-- Class
_list_node = {}
_list_node.__index = _list_node

-- Metatable
_list_node_mt = {}
_list_node_mt._next = nil
_list_node_mt._prev = nil
_list_node_mt._elem = nil
_list_node_mt.__call = function(self, value)
  local res = setmetatable({}, _list_node)
  res._elem = value
  return res
end
setmetatable(_list_node, _list_node_mt)

--[[ _list_iter ]]

-- Class
_list_iter = {}
_list_iter.__index = _list_iter
_list_iter.__eq = function(self, other)
  return self._impl == other._impl
end

-- Metatable
_list_iter_mt = {}
_list_iter_mt._impl = nil
_list_iter_mt.__call = function(self, node)
  local res = setmetatable({}, _list_iter)
  res._impl = node
  return res
end
setmetatable(_list_iter, _list_iter_mt)

-- Iterators
function _list_iter:next()
  return _list_iter(self._impl._next)
end

function _list_iter:prev()
  return _list_iter(self._impl._prev)
end

-- Access
function _list_iter:valueOf()
  return self._impl._elem
end

--[[ list ]]

-- Class
list = {}
list.__index = list
list.__len = function(self)
  return self._size
end

-- Metatable
list_mt = {}
list_mt.__call = function(self)
  local res = setmetatable({}, list)
  res._impl = _list_node(nil)
  res._impl._next = res._impl
  res._impl._prev = res._impl
  res._size = 0
  return res
end
setmetatable(list, list_mt)

-- Capacity
function list:empty()
  return _size == 0
end

-- Iterators
function list:front()
  if self ~= nil then
    return _list_iter(self._impl._next)
  end
end

function list:back()
  if self ~= nil then
    return _list_iter(self._impl)
  end
end

-- Modifiers
function list:insert(pos, elem)
  local temp = _list_node(elem)
  local node = pos._impl
  if node ~= nil and node._prev ~= nil then
    temp._prev = node._prev
    node._prev._next = temp
    temp._next = node
    node._prev = temp
    self._size = self._size + 1
  end
  return _list_iter(node)
end

function list:push_back(elem)
  return self:insert(self:back(), elem)
end

--[[ test ]]

local p = list()
p:push_back("45")
p:push_back(23)
p:push_back(true)
p:push_back({6,7})

print("length : " .. #p)
i = p:front()
while i ~= p:back() do
  print(i:valueOf())
  i = i:next()
end

--[[
length : 4
45
23
true
table: 0042ABB8
[Finished in 0.379s]
]]
