#ifndef PROXY_H_INCLUDED
#define PROXY_H_INCLUDED

#include <string>
#include <vector>

#include "utils/tribool.h"

using String = std::string;
using StringArray = std::vector<String>;

enum class ProxyType
{
    Unknown,
    Shadowsocks,
    ShadowsocksR,
    VMess,
    Trojan,
    Snell,
    HTTP,
    HTTPS,
    SOCKS5,
    WireGuard,
    VLESS,
    Hysteria,
    Hysteria2,
    TUIC,
    AnyTLS,
    Mieru
};

inline String getProxyTypeName(ProxyType type) {
    switch (type) {
        case ProxyType::Shadowsocks:
            return "SS";
        case ProxyType::ShadowsocksR:
            return "SSR";
        case ProxyType::VMess:
            return "VMess";
        case ProxyType::Trojan:
            return "Trojan";
        case ProxyType::Snell:
            return "Snell";
        case ProxyType::HTTP:
            return "HTTP";
        case ProxyType::HTTPS:
            return "HTTPS";
        case ProxyType::SOCKS5:
            return "SOCKS5";
        case ProxyType::WireGuard:
            return "WireGuard";
        case ProxyType::VLESS:
            return "Vless";
        case ProxyType::Hysteria:
            return "Hysteria";
        case ProxyType::Hysteria2:
            return "Hysteria2";
        case ProxyType::TUIC:
            return "Tuic";
        case ProxyType::AnyTLS:
            return "AnyTLS";
        default:
            return "Unknown";
    }
}

struct Proxy {
    ProxyType Type = ProxyType::Unknown;
    uint32_t Id = 0;
    uint32_t GroupId = 0;
    String Group;
    String Remark;
    String Hostname;
    uint16_t Port = 0;
    String CongestionControl;
    String Username;
    String Password;
    String EncryptMethod;
    String Plugin;
    String PluginOption;
    String Protocol;
    String ProtocolParam;
    String OBFS;
    String OBFSParam;
    String UserId;
    uint16_t AlterId = 0;
    String TransferProtocol;
    String FakeType;
    String AuthStr;
    uint16_t IdleSessionCheckInterval=30;
    uint16_t IdleSessionTimeout=30;
    uint16_t MinIdleSession=0;
    String TLSStr;
    bool TLSSecure = false;

    String Host;
    String Path;
    String Edge;

    String QUICSecure;
    String QUICSecret;

    tribool UDP;
    tribool XUDP;
    tribool TCPFastOpen;
    tribool AllowInsecure;
    tribool TLS13;

    uint16_t SnellVersion = 0;
    String ServerName;

    String SelfIP;
    String SelfIPv6;
    String PublicKey;
    String PrivateKey;
    String PreSharedKey;
    StringArray DnsServers;
    uint16_t Mtu = 0;
    String AllowedIPs = "0.0.0.0/0, ::/0";
    uint16_t KeepAlive = 0;
    String TestUrl;
    String ClientId;
    String Ports;
    String Auth;
    String Alpn;
    String UpMbps;
    String DownMbps;
    String Insecure;
    String Fingerprint;
    String OBFSPassword;
    String GRPCServiceName;
    String GRPCMode;
    String ShortId;
    String Flow;
    bool FlowShow = false;
    tribool DisableSni;
    uint32_t UpSpeed;
    uint32_t DownSpeed;
    String SNI;
    tribool ReduceRtt;
    String UdpRelayMode = "native";
    uint16_t RequestTimeout = 15000;
    String token;
    String UnderlyingProxy;
    std::vector<String> AlpnList;
    String PacketEncoding;
    String Multiplexing;
    tribool V2rayHttpUpgrade;
    
    // Hysteria2 specific fields
    tribool DisableMtuDiscovery;
    uint32_t HopInterval = 0;
    String Up;
    String Down;
    String Ca;
    String CaStr;
    uint32_t RecvWindowConn = 0;
    uint32_t RecvWindow = 0;
    uint32_t Cwnd = 0;
};

#define SS_DEFAULT_GROUP "SSProvider"
#define SSR_DEFAULT_GROUP "SSRProvider"
#define V2RAY_DEFAULT_GROUP "V2RayProvider"
#define SOCKS_DEFAULT_GROUP "SocksProvider"
#define HTTP_DEFAULT_GROUP "HTTPProvider"
#define TROJAN_DEFAULT_GROUP "TrojanProvider"
#define SNELL_DEFAULT_GROUP "SnellProvider"
#define WG_DEFAULT_GROUP "WireGuardProvider"
#define XRAY_DEFAULT_GROUP "XRayProvider"
#define HYSTERIA_DEFAULT_GROUP "HysteriaProvider"
#define HYSTERIA2_DEFAULT_GROUP "Hysteria2Provider"
#define TUIC_DEFAULT_GROUP "TuicProvider"
#define ANYTLS_DEFAULT_GROUP "AnyTLSProvider"
#define MIERU_DEFAULT_GROUP "MieruProvider"
#endif // PROXY_H_INCLUDED
