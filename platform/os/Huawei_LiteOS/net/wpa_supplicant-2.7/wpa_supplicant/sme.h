/*
 * wpa_supplicant - SME
 * Copyright (c) 2009-2010, Jouni Malinen <j@w1.fi>
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#ifndef SME_H
#define SME_H

#ifdef CONFIG_SME

void sme_authenticate(struct wpa_supplicant *wpa_s,
		      struct wpa_bss *bss, struct wpa_ssid *ssid);
void sme_associate(struct wpa_supplicant *wpa_s, enum wpas_mode mode,
		   const u8 *bssid, u16 auth_type);
void sme_event_auth(struct wpa_supplicant *wpa_s, union wpa_event_data *data);
int sme_update_ft_ies(struct wpa_supplicant *wpa_s, const u8 *md,
		      const u8 *ies, size_t ies_len);
void sme_event_assoc_reject(struct wpa_supplicant *wpa_s,
			    union wpa_event_data *data);
void sme_event_auth_timed_out(struct wpa_supplicant *wpa_s,
			      union wpa_event_data *data);
void sme_event_assoc_timed_out(struct wpa_supplicant *wpa_s,
			       union wpa_event_data *data);
void sme_event_disassoc(struct wpa_supplicant *wpa_s,
			struct disassoc_info *info);
void sme_event_unprot_disconnect(struct wpa_supplicant *wpa_s, const u8 *sa,
				 const u8 *da, u16 reason_code);
void sme_sa_query_rx(struct wpa_supplicant *wpa_s, const u8 *sa,
		     const u8 *data, size_t len);
void sme_state_changed(struct wpa_supplicant *wpa_s);
void sme_disassoc_while_authenticating(struct wpa_supplicant *wpa_s,
				       const u8 *prev_pending_bssid);
void sme_clear_on_disassoc(struct wpa_supplicant *wpa_s);
void sme_deinit(struct wpa_supplicant *wpa_s);

int sme_proc_obss_scan(struct wpa_supplicant *wpa_s);
void sme_sched_obss_scan(struct wpa_supplicant *wpa_s, int enable);
void sme_external_auth_trigger(struct wpa_supplicant *wpa_s,
			       union wpa_event_data *data);
void sme_external_auth_mgmt_rx(struct wpa_supplicant *wpa_s,
			       const u8 *auth_frame, size_t len);

#else /* CONFIG_SME */

static inline void sme_authenticate(struct wpa_supplicant *wpa_s,
				    struct wpa_bss *bss,
				    struct wpa_ssid *ssid)
{
	(void)wpa_s;
	(void)bss;
	(void)ssid;
}

static inline void sme_event_auth(struct wpa_supplicant *wpa_s,
				  union wpa_event_data *data)
{
	(void)wpa_s;
	(void)data;
}

static inline int sme_update_ft_ies(struct wpa_supplicant *wpa_s, const u8 *md,
				    const u8 *ies, size_t ies_len)
{
	(void)wpa_s;
	(void)md;
	(void)ies;
	(void)ies_len;
	return -1;
}


static inline void sme_event_assoc_reject(struct wpa_supplicant *wpa_s,
					  union wpa_event_data *data)
{
	(void)wpa_s;
	(void)data;
}

static inline void sme_event_auth_timed_out(struct wpa_supplicant *wpa_s,
					    union wpa_event_data *data)
{
	(void)wpa_s;
	(void)data;
}

static inline void sme_event_assoc_timed_out(struct wpa_supplicant *wpa_s,
					     union wpa_event_data *data)
{
	(void)wpa_s;
	(void)data;
}

static inline void sme_event_disassoc(struct wpa_supplicant *wpa_s,
				      struct disassoc_info *info)
{
	(void)wpa_s;
	(void)info;
}

static inline void sme_event_unprot_disconnect(struct wpa_supplicant *wpa_s,
					       const u8 *sa, const u8 *da,
					       u16 reason_code)
{
	(void)wpa_s;
	(void)sa;
	(void)da;
	(void)reason_code;
}

static inline void sme_state_changed(struct wpa_supplicant *wpa_s)
{
	(void)wpa_s;
}

static inline void
sme_disassoc_while_authenticating(struct wpa_supplicant *wpa_s,
				  const u8 *prev_pending_bssid)
{
	(void)wpa_s;
	(void)prev_pending_bssid;
}

static inline void sme_clear_on_disassoc(struct wpa_supplicant *wpa_s)
{
	(void)wpa_s;
}

static inline void sme_deinit(struct wpa_supplicant *wpa_s)
{
	(void)wpa_s;
}

static inline int sme_proc_obss_scan(struct wpa_supplicant *wpa_s)
{
	(void)wpa_s;
	return 0;
}

static inline void sme_sched_obss_scan(struct wpa_supplicant *wpa_s,
				       int enable)
{
	(void)wpa_s;
	(void)enable;
}

static inline void sme_external_auth_trigger(struct wpa_supplicant *wpa_s,
					     union wpa_event_data *data)
{
	(void)wpa_s;
	(void)data;
}

static inline void sme_external_auth_mgmt_rx(struct wpa_supplicant *wpa_s,
					     const u8 *auth_frame, size_t len)
{
	(void)wpa_s;
	(void)auth_frame;
	(void)len;
}

#endif /* CONFIG_SME */

#endif /* SME_H */
