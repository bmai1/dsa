import pandas as pd

def rearrange_products_table(products: pd.DataFrame) -> pd.DataFrame:
    # productId = []
    # store = []
    # price = []
    # for product_id, store1, store2, store3 in products.values:
    #     if isinstance(store1, int):
    #         productId.append(product_id)
    #         store.append('store1')
    #         price.append(store1)
    #     if isinstance(store2, int):
    #         productId.append(product_id)
    #         store.append('store2')
    #         price.append(store2)
    #     if isinstance(store3, int):
    #         productId.append(product_id)
    #         store.append('store3')
    #         price.append(store3)
    # return pd.DataFrame({ 'product_id': productId, 'store': store, 'price': price })

    return pd.melt(
        products, id_vars='product_id', var_name='store', value_name='price'
    ).dropna()


