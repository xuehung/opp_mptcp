#include <net/mac80211.h>
#include "stats.h"

extern struct opp_mptcp_stats *stats;

int skip_frame(struct sk_buff *skb, struct ieee80211_local *local)
{
    struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
    struct ieee80211_sub_if_data *sdata;

    return 1;
}

void opp_mptcp_rx(struct ieee80211_hw *hw, struct sk_buff *origskb)
{
    /*
	struct ieee80211_local *local = hw_to_local(hw);
	struct ieee80211_supported_band *sband;
	struct ieee80211_rate *rate = NULL;
	struct ieee80211_rx_status *status = IEEE80211_SKB_RXCB(origskb);
        struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)origskb->data;
	struct ieee80211_ack *ack_hdr;
	struct sk_buff *saved_skb;
	int rate_idx;
	static int err_count = 0;
    */
    //stats->total++;
    //ieee80211_rx(hw, origskb);
    return;
}

EXPORT_SYMBOL(opp_mptcp_rx);



/*
void ieee80211_coop_tx(struct sk_buff *skb, struct ieee80211_local *local)
{
	int ret, len = skb->len;

	//dev_hold(sdata->dev);
	coop_txinfo_setup(skb, local);

	// FIXME: should probably retry if failed
	ret = drv_tx(local, skb);

	if (ret != NETDEV_TX_OK) {
		if (skb->len != len) {
			coop_err("failed to tx\n");
                	dev_kfree_skb(skb);
			goto out;
		}
		coop_err("dropping\n");
	}

	mac80211_coop_stats->relayed++;
	mac80211_coop_stats->tx_bytes += skb->len;
  out:
	return;
}
*/
