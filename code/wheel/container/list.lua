--[[ _list_node ]]

-- Class
_list_node = {}
_list_node.__index = _list_node
_list_node.__gc = function(self)
  self._type = nil
  self._next = nil
  self._prev = nil
  self._elem = nil
end

-- Metatable
_list_node_mt = {}
_list_node_mt._type = "_list_node"
_list_node_mt._next = nil
_list_node_mt._prev = nil
_list_node_mt._elem = nil
_list_node_mt.__call = function(self, value)
  local res = setmetatable({}, _list_node)
  res._elem = value
  return res
end
setmetatable(_list_node, _list_node_mt)

-- Iterators
function _list_node:next()
  return self._next
end

function _list_node:prev()
  return self._prev
end

-- Access
function _list_node:valueOf()
  return self._elem
end

--[[ list ]]

-- Class
list = {}
list.__index = list
list.__len = function(self)
  return self._size
end
list.__gc = function(self)
  self:clear()
  self._type = nil
  self._impl = nil
  self._size = nil
end

-- Metatable
list_mt = {}
list._type = "list"
list._impl = nil
list._size = 0
list_mt.__call = function(self, arg)
  local res = setmetatable({}, list)
  res._impl = _list_node(nil)
  res._impl._next = res._impl
  res._impl._prev = res._impl
  res._size = 0
  if arg ~= nil then
    assert(type(arg) == "table")
    for i, v in ipairs(arg) do
      res:push_back(v)
    end
  end
  return res
end
setmetatable(list, list_mt)

-- Capacity
function list:empty()
  return _size == 0
end

-- Iterators
function list:front()
  return self._impl._next
end

function list:back()
  return self._impl
end

function list:find(value)
  local res = self:front()
  while res ~= self:back() do
    if res._elem == value then break end
    res = res._next
  end
  return res
end

function list:move(value)
  local node = self:find(value)
  if node ~= self:back() then self:erase(node) end
end

-- Modifiers
function list:insert(node, elem)
  assert(node ~= nil)
  local temp = _list_node(elem)
  temp._prev = node._prev
  node._prev._next = temp
  temp._next = node
  node._prev = temp
  self._size = self._size + 1
  return temp
end

function list:erase(node)
  assert(node ~= nil)
  node._prev._next = node._next
  node._next._prev = node._prev
  node._next = nil
  node._prev = nil
  node._elem = nil
  self._size = self._size - 1
end

function list:push_front(elem)
  assert(self._impl ~= nil)
  return self:insert(self:front(), elem)
end

function list:pop_front()
  local node = self:front()
  assert(node ~= self._impl)
  return self:erase(node)
end

function list:push_back(elem)
  assert(self._impl ~= nil)
  return self:insert(self:back(), elem)
end

function list:pop_back()
  local node = self:back():prev()
  assert(node ~= self._impl)
  return self:erase(node)
end

function list:swap(other)
  assert(other._type == "list")
  self._impl, other._impl = other._impl, self._impl
  self._size, other._size = other._size, self._size
end

function list:clear()
  while self._size ~= 0 do
    self:erase(self:front())
  end
end

-- Operations

function list:reverse()
  local node = self:front()
  while node ~= self:back() do
    node._prev, node._next = node._next, node._prev
    node = node._prev
  end
  node._prev, node._next = node._next, node._prev
end

--[[ test ]]

local q = list({1, 2})
q:push_front(true)
q:push_back(nil)
q:push_back("4")
q:push_back(5)
q:pop_back()
q:push_back({6,7})
q:move(2)
local p = list({8, 9})
p:swap(q)
q:clear()
p:reverse()
print("length : " .. #q)
i = p:front()
while i ~= p:back() do
  print(i:valueOf())
  i = i:next()
end

--[[
length : 0
table: 00C8AF38
4
nil
1
true
[Finished in 0.192s]
]]
