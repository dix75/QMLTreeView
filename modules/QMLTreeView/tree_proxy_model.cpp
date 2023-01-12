#include "tree_proxy_model.h"
#include "tree_model.h"

TreeProxyModel::TreeProxyModel(QObject* parent): QSortFilterProxyModel(parent)
{
  setRecursiveFilteringEnabled(true);
  sort(0);
}

void TreeProxyModel::setFilter(const QString& filter) noexcept
{
  if(_filter == filter)
    return;

  _filter = filter;
  emit filterChanged();

  invalidateFilter();
  reload();
}

const QString& TreeProxyModel::filter() const noexcept
{
  return _filter;
}

QModelIndex TreeProxyModel::rootIndex()
{
  return {};
}

 int TreeProxyModel::depth(const QModelIndex& index) const
 {
   return (static_cast<TreeModel*>(sourceModel()))->depth(mapToSource(index));
 }

void TreeProxyModel::clear()
{
  return (static_cast<TreeModel*>(sourceModel()))->clear();
}

void TreeProxyModel::reload()
{
  return (static_cast<TreeModel*>(sourceModel()))->reload();
}

bool TreeProxyModel::filterAcceptsRow(int row, const QModelIndex& index) const
{
  const auto& indx = sourceModel()->index(row, 0, index);
  const auto& name = indx.data(Qt::DisplayRole).toString();
  return name.contains(_filter);
}
