#pragma once 
#include "Register/Utility.hpp"
namespace Kvasir {
//Secure Real Time Clock
    namespace RtcTsr{    ///<RTC Time Seconds Register
        using Addr = Register::Address<0x4003d000,0x00000000,0,unsigned>;
        ///Time Seconds Register
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> tsr{}; 
    }
    namespace RtcTpr{    ///<RTC Time Prescaler Register
        using Addr = Register::Address<0x4003d004,0xffff0000,0,unsigned>;
        ///Time Prescaler Register
        constexpr Register::BitLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> tpr{}; 
    }
    namespace RtcTar{    ///<RTC Time Alarm Register
        using Addr = Register::Address<0x4003d008,0x00000000,0,unsigned>;
        ///Time Alarm Register
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> tar{}; 
    }
    namespace RtcTcr{    ///<RTC Time Compensation Register
        using Addr = Register::Address<0x4003d00c,0x00000000,0,unsigned>;
        ///Time Compensation Register
        enum class tcrVal {
            v10000000=0x00000080,     ///<Time prescaler register overflows every 32896 clock cycles.
            v11111111=0x000000ff,     ///<Time prescaler register overflows every 32769 clock cycles.
            v0=0x00000000,     ///<Time prescaler register overflows every 32768 clock cycles.
            v1=0x00000001,     ///<Time prescaler register overflows every 32767 clock cycles.
            v1111111=0x0000007f,     ///<Time prescaler register overflows every 32641 clock cycles.
        };
        namespace tcrValC{
            constexpr MPL::Value<tcrVal,tcrVal::v10000000> v10000000{};
            constexpr MPL::Value<tcrVal,tcrVal::v11111111> v11111111{};
            constexpr MPL::Value<tcrVal,tcrVal::v0> v0{};
            constexpr MPL::Value<tcrVal,tcrVal::v1> v1{};
            constexpr MPL::Value<tcrVal,tcrVal::v1111111> v1111111{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,tcrVal> tcr{}; 
        ///Compensation Interval Register
        constexpr Register::BitLocation<Addr,Register::maskFromRange(15,8),Register::ReadWriteAccess,unsigned> cir{}; 
        ///Time Compensation Value
        constexpr Register::BitLocation<Addr,Register::maskFromRange(23,16),Register::ReadWriteAccess,unsigned> tcv{}; 
        ///Compensation Interval Counter
        constexpr Register::BitLocation<Addr,Register::maskFromRange(31,24),Register::ReadWriteAccess,unsigned> cic{}; 
    }
    namespace RtcCr{    ///<RTC Control Register
        using Addr = Register::Address<0x4003d010,0xffffc0f0,0,unsigned>;
        ///Software Reset
        enum class swrVal {
            v0=0x00000000,     ///<No effect
            v1=0x00000001,     ///<Resets all RTC registers except for the SWR bit and the RTC_WAR and RTC_RAR registers. The SWR bit is cleared after VBAT POR and by software explicitly clearing it.
        };
        namespace swrValC{
            constexpr MPL::Value<swrVal,swrVal::v0> v0{};
            constexpr MPL::Value<swrVal,swrVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,swrVal> swr{}; 
        ///Wakeup Pin Enable
        enum class wpeVal {
            v0=0x00000000,     ///<Wakeup pin is disabled.
            v1=0x00000001,     ///<Wakeup pin is enabled and wakeup pin asserts if the RTC interrupt asserts and the chip is powered down.
        };
        namespace wpeValC{
            constexpr MPL::Value<wpeVal,wpeVal::v0> v0{};
            constexpr MPL::Value<wpeVal,wpeVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,wpeVal> wpe{}; 
        ///Supervisor Access
        enum class supVal {
            v0=0x00000000,     ///<Non-supervisor mode write accesses are not supported and generate a bus error.
            v1=0x00000001,     ///<Non-supervisor mode write accesses are supported.
        };
        namespace supValC{
            constexpr MPL::Value<supVal,supVal::v0> v0{};
            constexpr MPL::Value<supVal,supVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,supVal> sup{}; 
        ///Update Mode
        enum class umVal {
            v0=0x00000000,     ///<Registers cannot be written when locked.
            v1=0x00000001,     ///<Registers can be written when locked under limited conditions.
        };
        namespace umValC{
            constexpr MPL::Value<umVal,umVal::v0> v0{};
            constexpr MPL::Value<umVal,umVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,umVal> um{}; 
        ///Oscillator Enable
        enum class osceVal {
            v0=0x00000000,     ///<32.768 kHz oscillator is disabled.
            v1=0x00000001,     ///<32.768 kHz oscillator is enabled. After setting this bit, wait the oscillator startup time before enabling the time counter to allow the 32.768 kHz clock time to stabilize.
        };
        namespace osceValC{
            constexpr MPL::Value<osceVal,osceVal::v0> v0{};
            constexpr MPL::Value<osceVal,osceVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,osceVal> osce{}; 
        ///Clock Output
        enum class clkoVal {
            v0=0x00000000,     ///<The 32kHz clock is output to other peripherals
            v1=0x00000001,     ///<The 32kHz clock is not output to other peripherals
        };
        namespace clkoValC{
            constexpr MPL::Value<clkoVal,clkoVal::v0> v0{};
            constexpr MPL::Value<clkoVal,clkoVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,clkoVal> clko{}; 
        ///Oscillator 16pF load configure
        enum class sc16pVal {
            v0=0x00000000,     ///<Disable the load.
            v1=0x00000001,     ///<Enable the additional load.
        };
        namespace sc16pValC{
            constexpr MPL::Value<sc16pVal,sc16pVal::v0> v0{};
            constexpr MPL::Value<sc16pVal,sc16pVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,sc16pVal> sc16p{}; 
        ///Oscillator 8pF load configure
        enum class sc8pVal {
            v0=0x00000000,     ///<Disable the load.
            v1=0x00000001,     ///<Enable the additional load.
        };
        namespace sc8pValC{
            constexpr MPL::Value<sc8pVal,sc8pVal::v0> v0{};
            constexpr MPL::Value<sc8pVal,sc8pVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,sc8pVal> sc8p{}; 
        ///Oscillator 4pF load configure
        enum class sc4pVal {
            v0=0x00000000,     ///<Disable the load.
            v1=0x00000001,     ///<Enable the additional load.
        };
        namespace sc4pValC{
            constexpr MPL::Value<sc4pVal,sc4pVal::v0> v0{};
            constexpr MPL::Value<sc4pVal,sc4pVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,sc4pVal> sc4p{}; 
        ///Oscillator 2pF load configure
        enum class sc2pVal {
            v0=0x00000000,     ///<Disable the load.
            v1=0x00000001,     ///<Enable the additional load.
        };
        namespace sc2pValC{
            constexpr MPL::Value<sc2pVal,sc2pVal::v0> v0{};
            constexpr MPL::Value<sc2pVal,sc2pVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,sc2pVal> sc2p{}; 
    }
    namespace RtcSr{    ///<RTC Status Register
        using Addr = Register::Address<0x4003d014,0xffffffe8,0,unsigned>;
        ///Time Invalid Flag
        enum class tifVal {
            v0=0x00000000,     ///<Time is valid.
            v1=0x00000001,     ///<Time is invalid and time counter is read as zero.
        };
        namespace tifValC{
            constexpr MPL::Value<tifVal,tifVal::v0> v0{};
            constexpr MPL::Value<tifVal,tifVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,tifVal> tif{}; 
        ///Time Overflow Flag
        enum class tofVal {
            v0=0x00000000,     ///<Time overflow has not occurred.
            v1=0x00000001,     ///<Time overflow has occurred and time counter is read as zero.
        };
        namespace tofValC{
            constexpr MPL::Value<tofVal,tofVal::v0> v0{};
            constexpr MPL::Value<tofVal,tofVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,tofVal> tof{}; 
        ///Time Alarm Flag
        enum class tafVal {
            v0=0x00000000,     ///<Time alarm has not occurred.
            v1=0x00000001,     ///<Time alarm has occurred.
        };
        namespace tafValC{
            constexpr MPL::Value<tafVal,tafVal::v0> v0{};
            constexpr MPL::Value<tafVal,tafVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,tafVal> taf{}; 
        ///Time Counter Enable
        enum class tceVal {
            v0=0x00000000,     ///<Time counter is disabled.
            v1=0x00000001,     ///<Time counter is enabled.
        };
        namespace tceValC{
            constexpr MPL::Value<tceVal,tceVal::v0> v0{};
            constexpr MPL::Value<tceVal,tceVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,tceVal> tce{}; 
    }
    namespace RtcLr{    ///<RTC Lock Register
        using Addr = Register::Address<0x4003d018,0xffffff87,0,unsigned>;
        ///Time Compensation Lock
        enum class tclVal {
            v0=0x00000000,     ///<Time compensation register is locked and writes are ignored.
            v1=0x00000001,     ///<Time compensation register is not locked and writes complete as normal.
        };
        namespace tclValC{
            constexpr MPL::Value<tclVal,tclVal::v0> v0{};
            constexpr MPL::Value<tclVal,tclVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,tclVal> tcl{}; 
        ///Control Register Lock
        enum class crlVal {
            v0=0x00000000,     ///<Control register is locked and writes are ignored.
            v1=0x00000001,     ///<Control register is not locked and writes complete as normal.
        };
        namespace crlValC{
            constexpr MPL::Value<crlVal,crlVal::v0> v0{};
            constexpr MPL::Value<crlVal,crlVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,crlVal> crl{}; 
        ///Status Register Lock
        enum class srlVal {
            v0=0x00000000,     ///<Status register is locked and writes are ignored.
            v1=0x00000001,     ///<Status register is not locked and writes complete as normal.
        };
        namespace srlValC{
            constexpr MPL::Value<srlVal,srlVal::v0> v0{};
            constexpr MPL::Value<srlVal,srlVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,srlVal> srl{}; 
        ///Lock Register Lock
        enum class lrlVal {
            v0=0x00000000,     ///<Lock register is locked and writes are ignored.
            v1=0x00000001,     ///<Lock register is not locked and writes complete as normal.
        };
        namespace lrlValC{
            constexpr MPL::Value<lrlVal,lrlVal::v0> v0{};
            constexpr MPL::Value<lrlVal,lrlVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,lrlVal> lrl{}; 
    }
    namespace RtcIer{    ///<RTC Interrupt Enable Register
        using Addr = Register::Address<0x4003d01c,0xfffffff8,0,unsigned>;
        ///Time Invalid Interrupt Enable
        enum class tiieVal {
            v0=0x00000000,     ///<Time invalid flag does not generate an interrupt.
            v1=0x00000001,     ///<Time invalid flag does generate an interrupt.
        };
        namespace tiieValC{
            constexpr MPL::Value<tiieVal,tiieVal::v0> v0{};
            constexpr MPL::Value<tiieVal,tiieVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,tiieVal> tiie{}; 
        ///Time Overflow Interrupt Enable
        enum class toieVal {
            v0=0x00000000,     ///<Time overflow flag does not generate an interrupt.
            v1=0x00000001,     ///<Time overflow flag does generate an interrupt.
        };
        namespace toieValC{
            constexpr MPL::Value<toieVal,toieVal::v0> v0{};
            constexpr MPL::Value<toieVal,toieVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,toieVal> toie{}; 
        ///Time Alarm Interrupt Enable
        enum class taieVal {
            v0=0x00000000,     ///<Time alarm flag does not generate an interrupt.
            v1=0x00000001,     ///<Time alarm flag does generate an interrupt.
        };
        namespace taieValC{
            constexpr MPL::Value<taieVal,taieVal::v0> v0{};
            constexpr MPL::Value<taieVal,taieVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,taieVal> taie{}; 
    }
    namespace RtcWar{    ///<RTC Write Access Register
        using Addr = Register::Address<0x4003d800,0xffffff00,0,unsigned>;
        ///Time Seconds Register Write
        enum class tsrwVal {
            v0=0x00000000,     ///<Writes to the time seconds register are ignored.
            v1=0x00000001,     ///<Writes to the time seconds register complete as normal.
        };
        namespace tsrwValC{
            constexpr MPL::Value<tsrwVal,tsrwVal::v0> v0{};
            constexpr MPL::Value<tsrwVal,tsrwVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,tsrwVal> tsrw{}; 
        ///Time Prescaler Register Write
        enum class tprwVal {
            v0=0x00000000,     ///<Writes to the time prescaler register are ignored.
            v1=0x00000001,     ///<Writes to the time prescaler register complete as normal.
        };
        namespace tprwValC{
            constexpr MPL::Value<tprwVal,tprwVal::v0> v0{};
            constexpr MPL::Value<tprwVal,tprwVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,tprwVal> tprw{}; 
        ///Time Alarm Register Write
        enum class tarwVal {
            v0=0x00000000,     ///<Writes to the time alarm register are ignored.
            v1=0x00000001,     ///<Writes to the time alarm register complete as normal.
        };
        namespace tarwValC{
            constexpr MPL::Value<tarwVal,tarwVal::v0> v0{};
            constexpr MPL::Value<tarwVal,tarwVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,tarwVal> tarw{}; 
        ///Time Compensation Register Write
        enum class tcrwVal {
            v0=0x00000000,     ///<Writes to the time compensation register are ignored.
            v1=0x00000001,     ///<Writes to the time compensation register complete as normal.
        };
        namespace tcrwValC{
            constexpr MPL::Value<tcrwVal,tcrwVal::v0> v0{};
            constexpr MPL::Value<tcrwVal,tcrwVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,tcrwVal> tcrw{}; 
        ///Control Register Write
        enum class crwVal {
            v0=0x00000000,     ///<Writes to the control register are ignored.
            v1=0x00000001,     ///<Writes to the control register complete as normal.
        };
        namespace crwValC{
            constexpr MPL::Value<crwVal,crwVal::v0> v0{};
            constexpr MPL::Value<crwVal,crwVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,crwVal> crw{}; 
        ///Status Register Write
        enum class srwVal {
            v0=0x00000000,     ///<Writes to the status register are ignored.
            v1=0x00000001,     ///<Writes to the status register complete as normal.
        };
        namespace srwValC{
            constexpr MPL::Value<srwVal,srwVal::v0> v0{};
            constexpr MPL::Value<srwVal,srwVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,srwVal> srw{}; 
        ///Lock Register Write
        enum class lrwVal {
            v0=0x00000000,     ///<Writes to the lock register are ignored.
            v1=0x00000001,     ///<Writes to the lock register complete as normal.
        };
        namespace lrwValC{
            constexpr MPL::Value<lrwVal,lrwVal::v0> v0{};
            constexpr MPL::Value<lrwVal,lrwVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,lrwVal> lrw{}; 
        ///Interrupt Enable Register Write
        enum class ierwVal {
            v0=0x00000000,     ///<Writes to the interupt enable register are ignored.
            v1=0x00000001,     ///<Writes to the interrupt enable register complete as normal.
        };
        namespace ierwValC{
            constexpr MPL::Value<ierwVal,ierwVal::v0> v0{};
            constexpr MPL::Value<ierwVal,ierwVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,ierwVal> ierw{}; 
    }
    namespace RtcRar{    ///<RTC Read Access Register
        using Addr = Register::Address<0x4003d804,0xffffff00,0,unsigned>;
        ///Time Seconds Register Read
        enum class tsrrVal {
            v0=0x00000000,     ///<Reads to the time seconds register are ignored.
            v1=0x00000001,     ///<Reads to the time seconds register complete as normal.
        };
        namespace tsrrValC{
            constexpr MPL::Value<tsrrVal,tsrrVal::v0> v0{};
            constexpr MPL::Value<tsrrVal,tsrrVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,tsrrVal> tsrr{}; 
        ///Time Prescaler Register Read
        enum class tprrVal {
            v0=0x00000000,     ///<Reads to the time prescaler register are ignored.
            v1=0x00000001,     ///<Reads to the time prescaler register complete as normal.
        };
        namespace tprrValC{
            constexpr MPL::Value<tprrVal,tprrVal::v0> v0{};
            constexpr MPL::Value<tprrVal,tprrVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,tprrVal> tprr{}; 
        ///Time Alarm Register Read
        enum class tarrVal {
            v0=0x00000000,     ///<Reads to the time alarm register are ignored.
            v1=0x00000001,     ///<Reads to the time alarm register complete as normal.
        };
        namespace tarrValC{
            constexpr MPL::Value<tarrVal,tarrVal::v0> v0{};
            constexpr MPL::Value<tarrVal,tarrVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,tarrVal> tarr{}; 
        ///Time Compensation Register Read
        enum class tcrrVal {
            v0=0x00000000,     ///<Reads to the time compensation register are ignored.
            v1=0x00000001,     ///<Reads to the time compensation register complete as normal.
        };
        namespace tcrrValC{
            constexpr MPL::Value<tcrrVal,tcrrVal::v0> v0{};
            constexpr MPL::Value<tcrrVal,tcrrVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,tcrrVal> tcrr{}; 
        ///Control Register Read
        enum class crrVal {
            v0=0x00000000,     ///<Reads to the control register are ignored.
            v1=0x00000001,     ///<Reads to the control register complete as normal.
        };
        namespace crrValC{
            constexpr MPL::Value<crrVal,crrVal::v0> v0{};
            constexpr MPL::Value<crrVal,crrVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,crrVal> crr{}; 
        ///Status Register Read
        enum class srrVal {
            v0=0x00000000,     ///<Reads to the status register are ignored.
            v1=0x00000001,     ///<Reads to the status register complete as normal.
        };
        namespace srrValC{
            constexpr MPL::Value<srrVal,srrVal::v0> v0{};
            constexpr MPL::Value<srrVal,srrVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,srrVal> srr{}; 
        ///Lock Register Read
        enum class lrrVal {
            v0=0x00000000,     ///<Reads to the lock register are ignored.
            v1=0x00000001,     ///<Reads to the lock register complete as normal.
        };
        namespace lrrValC{
            constexpr MPL::Value<lrrVal,lrrVal::v0> v0{};
            constexpr MPL::Value<lrrVal,lrrVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,lrrVal> lrr{}; 
        ///Interrupt Enable Register Read
        enum class ierrVal {
            v0=0x00000000,     ///<Reads to the interrupt enable register are ignored.
            v1=0x00000001,     ///<Reads to the interrupt enable register complete as normal.
        };
        namespace ierrValC{
            constexpr MPL::Value<ierrVal,ierrVal::v0> v0{};
            constexpr MPL::Value<ierrVal,ierrVal::v1> v1{};
        }
        constexpr Register::BitLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,ierrVal> ierr{}; 
    }
}